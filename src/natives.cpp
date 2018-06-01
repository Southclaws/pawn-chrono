#include "natives.hpp"

cell Natives::TimeFormat(AMX* amx, cell* params)
{
    std::chrono::time_point<std::chrono::system_clock> ts(std::chrono::seconds(static_cast<int>(params[1])));
    std::string fmt = amx_GetCppString(amx, params[2]);

    auto in_time_t = std::chrono::system_clock::to_time_t(ts);
    std::tm buf;
    localtime_s(&buf, &in_time_t);

    char* output;
    strftime(output, params[4], fmt.c_str(), &buf);

    return amx_SetCppString(amx, params[3], std::string(output), params[4]);
}

cell Natives::TimeParse(AMX* amx, cell* params)
{
    // todo

    return 0;
}

cell Natives::TimeAdd(AMX* amx, cell* params)
{
    std::chrono::time_point<std::chrono::system_clock> ts(std::chrono::seconds(static_cast<int>(params[1])));
    std::chrono::duration<std::chrono::milliseconds> duration(std::chrono::seconds(static_cast<int>(params[2])));

    ts += duration;

    return static_cast<cell>(ts.time_since_epoch().count());
}
