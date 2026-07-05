#include "natives.hpp"

std::map<std::string, chrono::milliseconds> unitMap = {
    { "ms", chrono::milliseconds(1) },
    { "s", chrono::seconds(1) },
    { "m", chrono::minutes(1) },
    { "h", chrono::hours(1) },
    { "d", chrono::hours(24) }
};

cell Natives::Now(AMX* amx, cell* params)
{
    return static_cast<int>(std::chrono::seconds(std::time(NULL)).count());
}

cell Natives::TimeFormat(AMX* amx, cell* params)
{
    int unix_timestamp = static_cast<int>(params[1]);
    std::string fmt = amx_GetCppString(amx, params[2]);

    date::sys_seconds since_epoch(chrono::seconds{ unix_timestamp });

    std::ostringstream os;
    date::to_stream(os, fmt.c_str(), since_epoch);
    std::string output(os.str());

    return amx_SetCppString(amx, params[3], output, params[4]);
}

cell Natives::TimeParse(AMX* amx, cell* params)
{
    std::string string = amx_GetCppString(amx, params[1]);
    std::string fmt = amx_GetCppString(amx, params[2]);
    cell* output;
    amx_GetAddr(amx, params[3], &output);

    std::istringstream is(string);
    date::sys_seconds d;

	try {
		if (date::from_stream(is, fmt.c_str(), d).fail()) {
			return 1;
		}
	} catch (std::exception& e) {
		logprintf("ERROR: date::from_stream failed: %s", e.what());
		return 1;
	}

    *output = static_cast<cell>(d.time_since_epoch().count());

    return 0;
}

static int parseDurationMs(const std::string& input, long long& resultMs)
{
    size_t idx = 0,
           length = input.length();

    if (input[idx] == '-' || input[idx] == '+') {
        idx++;
    }

    if (!(input[idx] == '.' || '0' <= input[idx] && input[idx] <= '9')) {
        return 1;
    }

    int numberBegin = -1;
    long long value = 0;

    bool gotValue = false,
         gotUnit = false;

    std::string unit;
    resultMs = 0;

    while (idx <= length) {
        if (!gotValue) {
            if (numberBegin == -1) {
                numberBegin = idx;

                idx++;
                continue;
            } else {
                if (!('0' <= input[idx] && input[idx] <= '9')) {
                    gotValue = true;
                    value = std::stoll(input.substr(numberBegin, idx - numberBegin));
                    numberBegin = -1;

                    continue;
                }

                idx++;
                continue;
            }
        }
        if (!gotUnit) {
            if (input[idx] == 0 || !('a' <= input[idx] && input[idx] <= 'z')) {
                gotUnit = true;
                continue;
            }

            unit.push_back(input[idx]);

            idx++;
            continue;
        }

        if (unitMap.find(unit) == unitMap.end()) {
            return 2;
        }
        resultMs += value * unitMap.at(unit).count();

        if (input[idx] == 0) {
            break;
        }

        gotValue = false;
        gotUnit = false;
        unit = std::string();
    }

    return 0;
}

cell Natives::DurationParse(AMX* amx, cell* params)
{
    std::string input = amx_GetCppString(amx, params[1]);
    cell* output;
    amx_GetAddr(amx, params[2], &output);

    long long resultMs = 0;
    int ret = parseDurationMs(input, resultMs);
    if (ret != 0) {
        return ret;
    }

    *output = static_cast<cell>(resultMs);

    return 0;
}

cell Natives::DurationParseSeconds(AMX* amx, cell* params)
{
    std::string input = amx_GetCppString(amx, params[1]);
    cell* output;
    amx_GetAddr(amx, params[2], &output);

    long long resultMs = 0;
    int ret = parseDurationMs(input, resultMs);
    if (ret != 0) {
        return ret;
    }

    *output = static_cast<cell>(resultMs / 1000);

    return 0;
}
