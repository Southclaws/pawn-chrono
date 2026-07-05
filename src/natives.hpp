#ifndef CHRONO_NATIVES_H
#define CHRONO_NATIVES_H

#include <chrono>
#include <ctime>
#include <date/date.h>
#include <map>
#include <string>
namespace chrono = std::chrono;

#include <amx/amx2.h>

#include "common.hpp"

namespace Natives {
cell Now(AMX* amx, cell* params);
cell TimeFormat(AMX* amx, cell* params);
cell TimeParse(AMX* amx, cell* params);
cell DurationParse(AMX* amx, cell* params);
cell DurationParseSeconds(AMX* amx, cell* params);
}

#endif
