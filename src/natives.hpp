#ifndef CHRONO_NATIVES_H
#define CHRONO_NATIVES_H

#include <chrono>
#include <ctime>
#include <string>
#include <date/date.h>
namespace chrono = std::chrono;

#include <amx/amx2.h>

#include "common.hpp"

namespace Natives {
cell TimeFormat(AMX* amx, cell* params);
cell TimeParse(AMX* amx, cell* params);
cell TimeAdd(AMX* amx, cell* params);
}

#endif
