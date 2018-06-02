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

// const string[], const fmt[], &Timestamp:output
cell Natives::TimeParse(AMX* amx, cell* params)
{
    std::string string = amx_GetCppString(amx, params[1]);
    std::string fmt = amx_GetCppString(amx, params[2]);
    cell* output;
    amx_GetAddr(amx, params[3], &output);

    std::istringstream is(string);
    date::sys_seconds d;

    date::from_stream(is, fmt.c_str(), d);

    *output = d.time_since_epoch().count();

    return 0;
}
