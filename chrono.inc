// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_chrono
	#undef _inc_chrono
#endif
// custom include-guard to ensure we don't duplicate
#if defined _chrono_included
	#endinput
#endif
#define _chrono_included


// -
// Unit Conversions - Months/Years are rough approximations
// -

const Milliseconds:SecondInMilliseconds = Milliseconds:1_000;
const Milliseconds:MinuteInMilliseconds = Milliseconds:60_000;
const Milliseconds:HourInMilliseconds =   Milliseconds:3_600_000;
const Milliseconds:DayInMilliseconds =    Milliseconds:86_400_000;
const Milliseconds:WeekInMilliseconds =   Milliseconds:604_800_000;
const Milliseconds:MonthInMilliseconds =  Milliseconds:2_629_746_000;
// const Milliseconds:YearInMilliseconds =   Milliseconds:31556952000; // overflow!

const Seconds:MinuteInSeconds = Seconds:60;
const Seconds:HourInSeconds =   Seconds:3600;
const Seconds:DayInSeconds =    Seconds:86400;
const Seconds:WeekInSeconds =   Seconds:604800;
const Seconds:MonthInSeconds =  Seconds:2629746;
const Seconds:YearInSeconds =   Seconds:31556952;

const Minutes:HourInMinutes =  Minutes:60;
const Minutes:DayInMinutes =   Minutes:1440;
const Minutes:WeekInMinutes =  Minutes:10080;
const Minutes:MonthInMinutes = Minutes:(MonthInSeconds / 60);
const Minutes:YearInMinutes =  Minutes:(MonthInMinutes * 12);

const Hours:DayInHours =   Hours:12;
const Hours:WeekInHours =  Hours:(DayInHours * 7);
const Hours:MonthInHours = Hours:(MonthInMinutes / 60);
const Hours:YearInHours =  Hours:(MonthInHours * 12);

const Days:WeekInDays =  Days:7;
const Days:MonthInDays = Days:30; // 30.4375
const Days:YearInDays =  Days:365; // no leap years

const Weeks:YearInWeeks = Weeks:52;


// -
// Natives
// -

native Timestamp:Now() = gettime;
native Timestamp:TimeFormat(Timestamp:ts, const fmt[], output[], len = sizeof output);
native Timestamp:TimeAdd(Timestamp:ts, Duration:d);
