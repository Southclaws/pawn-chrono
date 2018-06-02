#include "natives.hpp"

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
    // todo

    return 0;
}

cell Natives::TimeAdd(AMX* amx, cell* params)
{
    //std::chrono::time_point<std::chrono::system_clock> ts(std::chrono::seconds(static_cast<int>(params[1])));
    //std::chrono::duration<std::chrono::milliseconds> duration(std::chrono::seconds(static_cast<int>(params[2])));

    //ts += duration;

	return 0; // static_cast<cell>(ts.time_since_epoch().count());
}
