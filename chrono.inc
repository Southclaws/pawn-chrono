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

#define TIME_UNITS {Milliseconds,Seconds,Minutes,Hours,Days,Weeks,Months,Years}

const Milliseconds:SecondInMilliseconds = Milliseconds:1_000;
const Milliseconds:MinuteInMilliseconds = Milliseconds:60_000;
const Milliseconds:HourInMilliseconds =   Milliseconds:3_600_000;
const Milliseconds:DayInMilliseconds =    Milliseconds:86_400_000;
const Milliseconds:WeekInMilliseconds =   Milliseconds:604_800_000;
const Milliseconds:MonthInMilliseconds =  Milliseconds:2_629_746_000;
// const Milliseconds:YearInMilliseconds =   Milliseconds:31556952000; // overflow!

const Seconds:MinuteInSeconds = Seconds:60;
const Seconds:HourInSeconds =   Seconds:3_600;
const Seconds:DayInSeconds =    Seconds:86_400;
const Seconds:WeekInSeconds =   Seconds:604_800;
const Seconds:MonthInSeconds =  Seconds:2_629_746;
const Seconds:YearInSeconds =   Seconds:31_556_952;

const Minutes:HourInMinutes =  Minutes:60;
const Minutes:DayInMinutes =   Minutes:1_440;
const Minutes:WeekInMinutes =  Minutes:10_080;
const Minutes:MonthInMinutes = Minutes:(Minutes:MonthInSeconds / Minutes:60);
const Minutes:YearInMinutes =  Minutes:(Minutes:MonthInMinutes * Minutes:12);

const Hours:DayInHours =   Hours:12;
const Hours:WeekInHours =  Hours:(Hours:DayInHours * Hours:7);
const Hours:MonthInHours = Hours:(Hours:MonthInMinutes / Hours:60);
const Hours:YearInHours =  Hours:(Hours:MonthInHours * Hours:12);

const Days:WeekInDays =  Days:7;
const Days:MonthInDays = Days:30; // 30.4375
const Days:YearInDays =  Days:365; // no leap years

const Weeks:YearInWeeks = Weeks:52;


// -
// Format Specifiers
// -

#define WEEKDAY_NAME_ABV  "%a" // The locale's abbreviated weekday name. If the value does not contain a valid weekday, std::ios::failbit is set.
#define WEEKDAY_NAME      "%A" // The locale's full weekday name. If the value does not contain a valid weekday, std::ios::failbit is set.
#define MONTH_NAME_ABV    "%b" // The locale's abbreviated month name. If the value does not contain a valid month, std::ios::failbit is set.
#define MONTH_NAME        "%B" // The locale's full month name. If the value does not contain a valid month, std::ios::failbit is set.
#define YEAR_DIV          "%C" // The year divided by 100 using floored division. If the result is a single decimal digit, it is prefixed with 0. The modified command %EC produces the locale's alternative representation of the century.
#define DAY_OF_MONTH      "%d" // The day of month as a decimal number. If the result is a single decimal digit, it is prefixed with 0. The modified command %Od produces the locale's alternative representation.
#define DATE_MDY          "%D" // Equivalent to %m/%d/%y - aka the dumb american date format
#define DAY_OF_MONTH_PAD  "%e" // The day of month as a decimal number. If the result is a single decimal digit, it is prefixed with a space. The modified command %Oe produces the locale's alternative representation.
#define DATE_YMD          "%F" // Equivalent to %Y-%m-%d - aka the international standard date format
#define WEEK_NUMBER_ISO   "%g" // The last two decimal digits of the ISO week-based year. If the result is a single digit it is prefixed by 0.
#define YEAR_PAD          "%G" // The ISO week-based year as a decimal number. If the result is less than four digits it is left-padded with 0 to four digits.
#define HOUR_24           "%H" // The hour (24-hour clock) as a decimal number. If the result is a single digit, it is prefixed with 0. The modified command %OH produces the locale's alternative representation.
#define HOUR_12           "%I" // The hour (12-hour clock) as a decimal number. If the result is a single digit, it is prefixed with 0. The modified command %OI produces the locale's alternative representation.
#define DAY_OF_YEAR       "%j" // The day of the year as a decimal number. Jan 1 is 001. If the result is less than three digits, it is left-padded with 0 to three digits.
#define MONTH             "%m" // The month as a decimal number. Jan is 01. If the result is a single digit, it is prefixed with 0. The modified command %Om produces the locale's alternative representation.
#define MINUTE            "%M" // The minute as a decimal number. If the result is a single digit, it is prefixed with 0. The modified command %OM produces the locale's alternative representation.
#define NEWLINE_CHAR      "%n" // A newline character.
#define MERIDIAN          "%p" // The locale's equivalent of the AM/PM designations associated with a 12-hour clock.
#define TIME_12           "%r" // The locale's 12-hour clock time.
#define HM_COLON          "%R" // Equivalent to %H:%M.
#define SECOND            "%S" // Seconds as a decimal number. If the number of seconds is less than 10, the result is prefixed with 0. If the precision of the input can not be exactly represented with seconds, then the format is a decimal floating point number with a fixed format and a precision matching that of the precision of the input (or to a microseconds precision if the conversion to floating point decimal seconds can not be made within 18 fractional digits). The character for the decimal point is localized according to the locale. The modified command %OS produces the locale's alternative representation.
#define TAB_CHAR          "%t" // A horizontal-tab character.
#define HMS_COLON         "%T" // Equivalent to %H:%M:%S.
#define WEEK_DAY          "%u" // The ISO weekday as a decimal number (1-7), where Monday is 1. The modified command %Ou produces the locale's alternative representation.
#define WEEK_OF_YEAR      "%U" // The week number of the year as a decimal number. The first Sunday of the year is the first day of week 01. Days of the same year prior to that are in week 00. If the result is a single digit, it is prefixed with 0. The modified command %OU produces the locale's alternative representation.
#define WEEK_OF_YEAR_ZERO "%V" // The ISO week-based week number as a decimal number. If the result is a single digit, it is prefixed with 0. The modified command %OV produces the locale's alternative representation.
#define WEEK_DAY_ZERO     "%w" // The weekday as a decimal number (0-6), where Sunday is 0. The modified command %Ow produces the locale's alternative representation.
#define WEEK_OF_YEAR_ALT  "%W" // The week number of the year as a decimal number. The first Monday of the year is the first day of week 01. Days of the same year prior to that are in week 00. If the result is a single digit, it is prefixed with 0. The modified command %OW produces the locale's alternative representation.
#define LOCALE_DATE       "%x" // The locale's date representation. The modified command %Ex produces the locale's alternate date representation.
#define LOCALE_TIME       "%X" // The locale's time representation. The modified command %Ex produces the locale's alternate time representation.
#define YEAR_ABV          "%y" // The last two decimal digits of the year. If the result is a single digit it is prefixed by 0.
#define YEAR              "%Y" // The year as a decimal number. If the result is less than four digits it is left-padded with 0 to four digits.
#define UTC_OFFSET        "%z" // The offset from UTC in the ISO 8601 format. For example -0430 refers to 4 hours 30 minutes behind UTC. If the offset is zero, +0000 is used. The modified commands %Ez and %Oz insert a : between the hours and minutes: -04:30. If the offset information is not available,  failbit will be set.
#define TIME_ZONE_ABV     "%Z" // The time zone abbreviation. If the time zone abbreviation is not available, failbit will be set.  UTC is used for sys_time.
#define PERCENTAGE        "%%" // A % character.


// -
// Format Tempates
// -

#define HUMAN_DATE         "%d/%m/%y"           // 31/05/18
#define ISO6801_TIME       "%H:%M:%S"           // 09:55:22
#define ISO6801_DATE       "%Y-%m-%d"           // 2018-05-31
#define ISO6801_FULL_UTC   "%Y-%m-%dT%H:%M:%SZ" // 2018-05-31T09:55:22Z
#define ISO6801_FULL_LOCAL "%Y-%m-%dT%H:%M:%S"  // 2018-05-31T09:55:22


// -
// Natives
// -

native Timestamp:Now();
native TimeFormat(Timestamp:ts, const fmt[], output[], len = sizeof output);
native TimeParse(const string[], const fmt[], &Timestamp:output);
native DurationParse(const string[], &Milliseconds:output);


// -
// Conversion Operators
// -

// Difference
stock Seconds:operator-(Timestamp:future, Timestamp:past) {
	return Seconds:(_:future - _:past);
}

// Seconds
stock Timestamp:operator+(Timestamp:t, Seconds:d) {
	return Timestamp:(_:t + _:d);
}
stock Timestamp:operator-(Timestamp:t, Seconds:d) {
	return Timestamp:(_:t - _:d);
}

// Minutes
stock Timestamp:operator+(Timestamp:t, Minutes:d) {
	return Timestamp:(_:t + (_:MinuteInSeconds * _:d));
}
stock Timestamp:operator-(Timestamp:t, Minutes:d) {
	return Timestamp:(_:t - (_:MinuteInSeconds * _:d));
}

// Hours
stock Timestamp:operator+(Timestamp:t, Hours:d) {
	return Timestamp:(_:t + (_:HourInSeconds * _:d));
}
stock Timestamp:operator-(Timestamp:t, Hours:d) {
	return Timestamp:(_:t - (_:HourInSeconds * _:d));
}

// Days
stock Timestamp:operator+(Timestamp:t, Days:d) {
	return Timestamp:(_:t + (_:DayInSeconds * _:d));
}
stock Timestamp:operator-(Timestamp:t, Days:d) {
	return Timestamp:(_:t - (_:DayInSeconds * _:d));
}


// -
// Helpers
// -

stock DurationFormat(Seconds:duration, output[], len = sizeof output) {
	new
		Seconds:years,
		Seconds:days,
		Seconds:hours,
		Seconds:minutes;

	if(duration > YearInSeconds) {
		years = (duration / YearInSeconds);
		duration -= (YearInSeconds * years);
	}

	if(duration > DayInSeconds) {
		days = (duration / DayInSeconds);
		duration -= (DayInSeconds * days);
	}

	if(duration > HourInSeconds) {
		hours = (duration / HourInSeconds);
		duration -= (HourInSeconds * hours);
	}

	if(duration > MinuteInSeconds) {
		minutes = (duration / MinuteInSeconds);
		duration -= (MinuteInSeconds * minutes);
	}

	if(years > Seconds:0) {
		format(
			output,
			len,
			"%s%d year%s",
			output,
			_:years,
			(_:years > 1) ? ("s, ") : (", ")
		);
	}
	if(days > Seconds:0) {
		format(
			output,
			len,
			"%s%d day%s",
			output,
			_:days,
			(_:days > 1) ? ("s, ") : (", ")
		);
	}
	if(hours > Seconds:0) {
		format(
			output,
			len,
			"%s%d hour%s",
			output,
			_:hours,
			(_:hours > 1) ? ("s, ") : (", ")
		);
	}
	if(minutes > Seconds:0) {
		format(
			output,
			len,
			"%s%d minute%s",
			output,
			_:minutes,
			(_:minutes > 1) ? ("s, ") : (", ")
		);
	}

	if(duration > Seconds:0) {
		format(
			output,
			len,
			"%s%d second%s",
			output,
			_:duration,
			(_:duration > 1) ? ("s, ") : (", ")
		);
	}

	// trim the trailing comma
	output[strlen(output) - 2] = EOS;

	return 0;
}


// -
// Time Zones (Should be moved to C++ at some point)
// -

#define MAX_TIMEZONE (439)
#define MAX_TIMEZONE_NAME (32)

enum E_TIMEZONE_OFFSET {
    TIMEZONE_NAME[MAX_TIMEZONE_NAME], // the timezone name
    TIMEZONE_OFFSET                   // the offset in seconds
}

new TimeZoneOffset[MAX_TIMEZONE][E_TIMEZONE_OFFSET] = {
    {"Africa/Abidjan", 0},
    {"Africa/Accra", 0},
    {"Africa/Addis_Ababa", 10800},
    {"Africa/Algiers", 3600},
    {"Africa/Asmara", 10800},
    {"Africa/Bamako", 0},
    {"Africa/Bangui", 3600},
    {"Africa/Banjul", 0},
    {"Africa/Bissau", 0},
    {"Africa/Blantyre", 7200},
    {"Africa/Brazzaville", 3600},
    {"Africa/Bujumbura", 7200},
    {"Africa/Cairo", 7200},
    {"Africa/Casablanca", 0},
    {"Africa/Ceuta", 7200},
    {"Africa/Conakry", 0},
    {"Africa/Dakar", 0},
    {"Africa/Dar_es_Salaam", 10800},
    {"Africa/Djibouti", 10800},
    {"Africa/Douala", 3600},
    {"Africa/El_Aaiun", 0},
    {"Africa/Freetown", 0},
    {"Africa/Gaborone", 7200},
    {"Africa/Harare", 7200},
    {"Africa/Johannesburg", 7200},
    {"Africa/Juba", 10800},
    {"Africa/Kampala", 10800},
    {"Africa/Khartoum", 10800},
    {"Africa/Kigali", 7200},
    {"Africa/Kinshasa", 3600},
    {"Africa/Lagos", 3600},
    {"Africa/Libreville", 3600},
    {"Africa/Lome", 0},
    {"Africa/Luanda", 3600},
    {"Africa/Lubumbashi", 7200},
    {"Africa/Lusaka", 7200},
    {"Africa/Malabo", 3600},
    {"Africa/Maputo", 7200},
    {"Africa/Maseru", 7200},
    {"Africa/Mbabane", 7200},
    {"Africa/Mogadishu", 10800},
    {"Africa/Monrovia", 0},
    {"Africa/Nairobi", 10800},
    {"Africa/Ndjamena", 3600},
    {"Africa/Niamey", 3600},
    {"Africa/Nouakchott", 0},
    {"Africa/Ouagadougou", 0},
    {"Africa/Porto-Novo", 3600},
    {"Africa/Sao_Tome", 0},
    {"Africa/Tripoli", 7200},
    {"Africa/Tunis", 3600},
    {"Africa/Windhoek", 3600},
    {"America/Adak", 54000},
    {"America/Anchorage", 57600},
    {"America/Anguilla", 72000},
    {"America/Antigua", 72000},
    {"America/Araguaina", 75600},
    {"America/Argentina/Buenos_Aires", 75600},
    {"America/Argentina/Catamarca", 75600},
    {"America/Argentina/Cordoba", 75600},
    {"America/Argentina/Jujuy", 75600},
    {"America/Argentina/La_Rioja", 75600},
    {"America/Argentina/Mendoza", 75600},
    {"America/Argentina/Rio_Gallegos", 75600},
    {"America/Argentina/Salta", 75600},
    {"America/Argentina/San_Juan", 75600},
    {"America/Argentina/San_Luis", 72000},
    {"America/Argentina/Tucuman", 75600},
    {"America/Argentina/Ushuaia", 75600},
    {"America/Aruba", 72000},
    {"America/Asuncion", 72000},
    {"America/Atikokan", 68400},
    {"America/Bahia", 75600},
    {"America/Bahia_Banderas", 64800},
    {"America/Barbados", 72000},
    {"America/Belem", 75600},
    {"America/Belize", 64800},
    {"America/Blanc-Sablon", 72000},
    {"America/Boa_Vista", 72000},
    {"America/Bogota", 68400},
    {"America/Boise", 64800},
    {"America/Cambridge_Bay", 64800},
    {"America/Campo_Grande", 72000},
    {"America/Cancun", 68400},
    {"America/Caracas", 70200},
    {"America/Cayenne", 75600},
    {"America/Cayman", 68400},
    {"America/Chicago", 68400},
    {"America/Chihuahua", 64800},
    {"America/Costa_Rica", 64800},
    {"America/Creston", 61200},
    {"America/Cuiaba", 72000},
    {"America/Curacao", 72000},
    {"America/Danmarkshavn", 0},
    {"America/Dawson", 61200},
    {"America/Dawson_Creek", 61200},
    {"America/Denver", 64800},
    {"America/Detroit", 72000},
    {"America/Dominica", 72000},
    {"America/Edmonton", 64800},
    {"America/Eirunepe", 72000},
    {"America/El_Salvador", 64800},
    {"America/Fort_Nelson", 61200},
    {"America/Fortaleza", 75600},
    {"America/Glace_Bay", 75600},
    {"America/Godthab", 79200},
    {"America/Goose_Bay", 75600},
    {"America/Grand_Turk", 72000},
    {"America/Grenada", 72000},
    {"America/Guadeloupe", 72000},
    {"America/Guatemala", 64800},
    {"America/Guayaquil", 68400},
    {"America/Guyana", 72000},
    {"America/Halifax", 75600},
    {"America/Havana", 72000},
    {"America/Hermosillo", 61200},
    {"America/Indiana/Indianapolis", 72000},
    {"America/Indiana/Knox", 68400},
    {"America/Indiana/Marengo", 72000},
    {"America/Indiana/Petersburg", 72000},
    {"America/Indiana/Tell_City", 68400},
    {"America/Indiana/Vevay", 72000},
    {"America/Indiana/Vincennes", 72000},
    {"America/Indiana/Winamac", 72000},
    {"America/Inuvik", 64800},
    {"America/Iqaluit", 72000},
    {"America/Jamaica", 68400},
    {"America/Juneau", 57600},
    {"America/Kentucky/Louisville", 72000},
    {"America/Kentucky/Monticello", 72000},
    {"America/Kralendijk", 72000},
    {"America/La_Paz", 72000},
    {"America/Lima", 68400},
    {"America/Los_Angeles", 61200},
    {"America/Lower_Princes", 72000},
    {"America/Maceio", 75600},
    {"America/Managua", 64800},
    {"America/Manaus", 72000},
    {"America/Marigot", 72000},
    {"America/Martinique", 72000},
    {"America/Matamoros", 68400},
    {"America/Mazatlan", 64800},
    {"America/Menominee", 68400},
    {"America/Merida", 68400},
    {"America/Metlakatla", 57600},
    {"America/Mexico_City", 68400},
    {"America/Miquelon", 79200},
    {"America/Moncton", 75600},
    {"America/Monterrey", 68400},
    {"America/Montevideo", 75600},
    {"America/Montserrat", 72000},
    {"America/Nassau", 72000},
    {"America/New_York", 72000},
    {"America/Nipigon", 72000},
    {"America/Nome", 57600},
    {"America/Noronha", 79200},
    {"America/North_Dakota/Beulah", 64800},
    {"America/North_Dakota/Center", 68400},
    {"America/North_Dakota/New_Salem", 68400},
    {"America/Ojinaga", 64800},
    {"America/Panama", 68400},
    {"America/Pangnirtung", 72000},
    {"America/Paramaribo", 75600},
    {"America/Phoenix", 61200},
    {"America/Port-au-Prince", 68400},
    {"America/Port_of_Spain", 72000},
    {"America/Porto_Velho", 72000},
    {"America/Puerto_Rico", 72000},
    {"America/Punta_Arenas", 72000},
    {"America/Rainy_River", 68400},
    {"America/Rankin_Inlet", 68400},
    {"America/Recife", 75600},
    {"America/Regina", 64800},
    {"America/Resolute", 68400},
    {"America/Rio_Branco", 72000},
    {"America/Santarem", 75600},
    {"America/Santiago", 72000},
    {"America/Santo_Domingo", 72000},
    {"America/Sao_Paulo", 75600},
    {"America/Scoresbysund", 0},
    {"America/Sitka", 57600},
    {"America/St_Barthelemy", 72000},
    {"America/St_Johns", 77400},
    {"America/St_Kitts", 72000},
    {"America/St_Lucia", 72000},
    {"America/St_Thomas", 72000},
    {"America/St_Vincent", 72000},
    {"America/Swift_Current", 64800},
    {"America/Tegucigalpa", 64800},
    {"America/Thule", 75600},
    {"America/Thunder_Bay", 72000},
    {"America/Tijuana", 61200},
    {"America/Toronto", 72000},
    {"America/Tortola", 72000},
    {"America/Vancouver", 61200},
    {"America/Whitehorse", 61200},
    {"America/Winnipeg", 68400},
    {"America/Yakutat", 57600},
    {"America/Yellowknife", 64800},
    {"Antarctica/Casey", 28800},
    {"Antarctica/Davis", 25200},
    {"Antarctica/DumontDUrville", 36000},
    {"Antarctica/Macquarie", 36000},
    {"Antarctica/Mawson", 21600},
    {"Antarctica/McMurdo", 43200},
    {"Antarctica/Palmer", 72000},
    {"Antarctica/Rothera", 75600},
    {"Antarctica/Syowa", 10800},
    {"Antarctica/Troll", 7200},
    {"Antarctica/Vostok", 21600},
    {"Arctic/Longyearbyen", 7200},
    {"Asia/Aden", 10800},
    {"Asia/Almaty", 21600},
    {"Asia/Amman", 10800},
    {"Asia/Anadyr", 46800},
    {"Asia/Aqtau", 18000},
    {"Asia/Aqtobe", 18000},
    {"Asia/Ashgabat", 18000},
    {"Asia/Atyrau", 18000},
    {"Asia/Baghdad", 10800},
    {"Asia/Bahrain", 10800},
    {"Asia/Baku", 18000},
    {"Asia/Bangkok", 25200},
    {"Asia/Barnaul", 25200},
    {"Asia/Beirut", 10800},
    {"Asia/Bishkek", 21600},
    {"Asia/Brunei", 28800},
    {"Asia/Chita", 36000},
    {"Asia/Choibalsan", 28800},
    {"Asia/Colombo", 19800},
    {"Asia/Damascus", 10800},
    {"Asia/Dhaka", 25200},
    {"Asia/Dili", 32400},
    {"Asia/Dubai", 14400},
    {"Asia/Dushanbe", 18000},
    {"Asia/Famagusta", 10800},
    {"Asia/Gaza", 10800},
    {"Asia/Hebron", 10800},
    {"Asia/Ho_Chi_Minh", 25200},
    {"Asia/Hong_Kong", 28800},
    {"Asia/Hovd", 25200},
    {"Asia/Irkutsk", 32400},
    {"Asia/Jakarta", 25200},
    {"Asia/Jayapura", 32400},
    {"Asia/Jerusalem", 10800},
    {"Asia/Kabul", 16200},
    {"Asia/Kamchatka", 46800},
    {"Asia/Karachi", 21600},
    {"Asia/Kathmandu", 20700},
    {"Asia/Khandyga", 39600},
    {"Asia/Kolkata", 19800},
    {"Asia/Krasnoyarsk", 28800},
    {"Asia/Kuala_Lumpur", 28800},
    {"Asia/Kuching", 28800},
    {"Asia/Kuwait", 10800},
    {"Asia/Macau", 28800},
    {"Asia/Magadan", 43200},
    {"Asia/Makassar", 28800},
    {"Asia/Manila", 28800},
    {"Asia/Muscat", 14400},
    {"Asia/Nicosia", 10800},
    {"Asia/Novokuznetsk", 28800},
    {"Asia/Novosibirsk", 25200},
    {"Asia/Omsk", 25200},
    {"Asia/Oral", 18000},
    {"Asia/Phnom_Penh", 25200},
    {"Asia/Pontianak", 25200},
    {"Asia/Pyongyang", 32400},
    {"Asia/Qatar", 10800},
    {"Asia/Qyzylorda", 21600},
    {"Asia/Riyadh", 10800},
    {"Asia/Sakhalin", 39600},
    {"Asia/Samarkand", 18000},
    {"Asia/Seoul", 32400},
    {"Asia/Shanghai", 28800},
    {"Asia/Singapore", 28800},
    {"Asia/Srednekolymsk", 43200},
    {"Asia/Taipei", 28800},
    {"Asia/Tashkent", 18000},
    {"Asia/Tbilisi", 14400},
    {"Asia/Tehran", 16200},
    {"Asia/Thimphu", 21600},
    {"Asia/Tokyo", 32400},
    {"Asia/Tomsk", 25200},
    {"Asia/Ulaanbaatar", 28800},
    {"Asia/Urumqi", 21600},
    {"Asia/Ust-Nera", 43200},
    {"Asia/Vientiane", 25200},
    {"Asia/Vladivostok", 39600},
    {"Asia/Yakutsk", 36000},
    {"Asia/Yangon", 23400},
    {"Asia/Yekaterinburg", 21600},
    {"Asia/Yerevan", 18000},
    {"Atlantic/Azores", 0},
    {"Atlantic/Bermuda", 75600},
    {"Atlantic/Canary", 3600},
    {"Atlantic/Cape_Verde", 82800},
    {"Atlantic/Faroe", 3600},
    {"Atlantic/Madeira", 3600},
    {"Atlantic/Reykjavik", 0},
    {"Atlantic/South_Georgia", 79200},
    {"Atlantic/St_Helena", 0},
    {"Atlantic/Stanley", 72000},
    {"Australia/Adelaide", 34200},
    {"Australia/Brisbane", 36000},
    {"Australia/Broken_Hill", 34200},
    {"Australia/Currie", 36000},
    {"Australia/Darwin", 34200},
    {"Australia/Eucla", 31500},
    {"Australia/Hobart", 36000},
    {"Australia/Lindeman", 36000},
    {"Australia/Lord_Howe", 37800},
    {"Australia/Melbourne", 36000},
    {"Australia/Perth", 28800},
    {"Australia/Sydney", 36000},
    {"Canada/Atlantic", 75600},
    {"Canada/Central", 68400},
    {"Canada/Eastern", 72000},
    {"Canada/Mountain", 64800},
    {"Canada/Newfoundland", 77400},
    {"Canada/Pacific", 61200},
    {"Europe/Amsterdam", 7200},
    {"Europe/Andorra", 7200},
    {"Europe/Astrakhan", 14400},
    {"Europe/Athens", 10800},
    {"Europe/Belgrade", 7200},
    {"Europe/Berlin", 7200},
    {"Europe/Bratislava", 7200},
    {"Europe/Brussels", 7200},
    {"Europe/Bucharest", 10800},
    {"Europe/Budapest", 7200},
    {"Europe/Busingen", 7200},
    {"Europe/Chisinau", 10800},
    {"Europe/Copenhagen", 7200},
    {"Europe/Dublin", 3600},
    {"Europe/Gibraltar", 7200},
    {"Europe/Guernsey", 3600},
    {"Europe/Helsinki", 10800},
    {"Europe/Isle_of_Man", 3600},
    {"Europe/Istanbul", 10800},
    {"Europe/Jersey", 3600},
    {"Europe/Kaliningrad", 10800},
    {"Europe/Kiev", 10800},
    {"Europe/Kirov", 14400},
    {"Europe/Lisbon", 3600},
    {"Europe/Ljubljana", 7200},
    {"Europe/London", 3600},
    {"Europe/Luxembourg", 7200},
    {"Europe/Madrid", 7200},
    {"Europe/Malta", 7200},
    {"Europe/Mariehamn", 10800},
    {"Europe/Minsk", 10800},
    {"Europe/Monaco", 7200},
    {"Europe/Moscow", 14400},
    {"Europe/Oslo", 7200},
    {"Europe/Paris", 7200},
    {"Europe/Podgorica", 7200},
    {"Europe/Prague", 7200},
    {"Europe/Riga", 10800},
    {"Europe/Rome", 7200},
    {"Europe/Samara", 18000},
    {"Europe/San_Marino", 7200},
    {"Europe/Sarajevo", 7200},
    {"Europe/Saratov", 14400},
    {"Europe/Simferopol", 10800},
    {"Europe/Skopje", 7200},
    {"Europe/Sofia", 10800},
    {"Europe/Stockholm", 7200},
    {"Europe/Tallinn", 10800},
    {"Europe/Tirane", 7200},
    {"Europe/Ulyanovsk", 14400},
    {"Europe/Uzhgorod", 10800},
    {"Europe/Vaduz", 7200},
    {"Europe/Vatican", 7200},
    {"Europe/Vienna", 7200},
    {"Europe/Vilnius", 10800},
    {"Europe/Volgograd", 14400},
    {"Europe/Warsaw", 7200},
    {"Europe/Zagreb", 7200},
    {"Europe/Zaporozhye", 10800},
    {"Europe/Zurich", 7200},
    {"GMT", 0},
    {"Indian/Antananarivo", 10800},
    {"Indian/Chagos", 21600},
    {"Indian/Christmas", 25200},
    {"Indian/Cocos", 23400},
    {"Indian/Comoro", 10800},
    {"Indian/Kerguelen", 18000},
    {"Indian/Mahe", 14400},
    {"Indian/Maldives", 18000},
    {"Indian/Mauritius", 14400},
    {"Indian/Mayotte", 10800},
    {"Indian/Reunion", 14400},
    {"Pacific/Apia", 46800},
    {"Pacific/Auckland", 43200},
    {"Pacific/Bougainville", 36000},
    {"Pacific/Chatham", 45900},
    {"Pacific/Chuuk", 36000},
    {"Pacific/Easter", 64800},
    {"Pacific/Efate", 39600},
    {"Pacific/Enderbury", 46800},
    {"Pacific/Fakaofo", 46800},
    {"Pacific/Fiji", 43200},
    {"Pacific/Funafuti", 43200},
    {"Pacific/Galapagos", 64800},
    {"Pacific/Gambier", 54000},
    {"Pacific/Guadalcanal", 39600},
    {"Pacific/Guam", 36000},
    {"Pacific/Honolulu", 50400},
    {"Pacific/Kiritimati", 50400},
    {"Pacific/Kosrae", 39600},
    {"Pacific/Kwajalein", 43200},
    {"Pacific/Majuro", 43200},
    {"Pacific/Marquesas", 52200},
    {"Pacific/Midway", 46800},
    {"Pacific/Nauru", 43200},
    {"Pacific/Niue", 46800},
    {"Pacific/Norfolk", 41400},
    {"Pacific/Noumea", 39600},
    {"Pacific/Pago_Pago", 46800},
    {"Pacific/Palau", 32400},
    {"Pacific/Pitcairn", 57600},
    {"Pacific/Pohnpei", 39600},
    {"Pacific/Port_Moresby", 36000},
    {"Pacific/Rarotonga", 50400},
    {"Pacific/Saipan", 36000},
    {"Pacific/Tahiti", 50400},
    {"Pacific/Tarawa", 43200},
    {"Pacific/Tongatapu", 46800},
    {"Pacific/Wake", 43200},
    {"Pacific/Wallis", 43200},
    {"US/Alaska", 57600},
    {"US/Arizona", 61200},
    {"US/Central", 68400},
    {"US/Eastern", 72000},
    {"US/Hawaii", 50400},
    {"US/Mountain", 64800},
    {"US/Pacific", 61200},
    {"UTC", 0}
};
