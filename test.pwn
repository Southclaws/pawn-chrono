#define RUN_TESTS

#include "chrono.inc"

#include <a_samp>
#include <strlib>
#include <YSI\y_testing>


main() {
    //
}

Test:DurationFormat() {
    new output[256];
    DurationFormat(Seconds:((86400 * 390) + 3800), output);
    print(output);
    ASSERT(!strcmp(output, "1 year, 24 days, 19 hours, 14 minutes"));
}

Test:DurationParse_Mil() {
    new Milliseconds:output;
    new ret = DurationParse("5ms", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:5);
}

Test:DurationParse_Sec() {
    new Milliseconds:output;
    new ret = DurationParse("5s", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:5000);
}

Test:DurationParse_Min() {
    new Milliseconds:output;
    new ret = DurationParse("10m", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:600000);
}

Test:DurationParse_Hour() {
    new Milliseconds:output;
    new ret = DurationParse("3h", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:10800000);
}

Test:DurationParse_Day() {
    new Milliseconds:output;
    new ret = DurationParse("1d", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:86400000);
}

Test:DurationParse_MinSec() {
    new Milliseconds:output;
    new ret = DurationParse("8m5s", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:485000);
}

Test:DurationParse_All() {
    new Milliseconds:output;
    new ret = DurationParse("1d3h10m5s5ms", output);
    printf("- output: %d: %d", ret, _:output);
    ASSERT(output == Milliseconds:(86400000 + 10800000 + 600000 + 5000 + 5));
}

Test:Now() {
    new Timestamp:now = Now();
    new nowbare = gettime();
    ASSERT(_:now == nowbare);
}

Test:TimeFormat_WEEKDAY_NAME_ABV() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEKDAY_NAME_ABV, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "Sat"));
}

Test:TimeFormat_WEEKDAY_NAME() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEKDAY_NAME, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "Saturday"));
}

Test:TimeFormat_MONTH_NAME_ABV() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, MONTH_NAME_ABV, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "Jun"));
}

Test:TimeFormat_MONTH_NAME() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, MONTH_NAME, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "June"));
}

Test:TimeFormat_YEAR_DIV() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, YEAR_DIV, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "20"));
}

Test:TimeFormat_DAY_OF_MONTH() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, DAY_OF_MONTH, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "02"));
}

Test:TimeFormat_DATE_MDY() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, DATE_MDY, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "06/02/18"));
}

Test:TimeFormat_DAY_OF_MONTH_PAD() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, DAY_OF_MONTH_PAD, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, " 2"));
}

Test:TimeFormat_DATE_YMD() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, DATE_YMD, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "2018-06-02"));
}

Test:TimeFormat_WEEK_NUMBER_ISO() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEK_NUMBER_ISO, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "18"));
}

Test:TimeFormat_YEAR_PAD() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, YEAR_PAD, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "2018"));
}

Test:TimeFormat_HOUR_24() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, HOUR_24, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "08"));
}

Test:TimeFormat_HOUR_12() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, HOUR_12, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "08"));
}

Test:TimeFormat_DAY_OF_YEAR() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, DAY_OF_YEAR, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "153"));
}

Test:TimeFormat_MONTH() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, MONTH, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "06"));
}

Test:TimeFormat_MINUTE() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, MINUTE, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "47"));
}

Test:TimeFormat_NEWLINE_CHAR() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, NEWLINE_CHAR, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "\n"));
}

Test:TimeFormat_MERIDIAN() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, MERIDIAN, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "AM"));
}

Test:TimeFormat_TIME_12() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, TIME_12, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "08:47:12", false, 8));
}

Test:TimeFormat_HM_COLON() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, HM_COLON, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "08:47"));
}

Test:TimeFormat_SECOND() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, SECOND, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "12"));
}

Test:TimeFormat_TAB_CHAR() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, TAB_CHAR, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "\t"));
}

Test:TimeFormat_HMS_COLON() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, HMS_COLON, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "08:47:12"));
}

Test:TimeFormat_WEEK_DAY() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEK_DAY, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "6"));
}

Test:TimeFormat_WEEK_OF_YEAR() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEK_OF_YEAR, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "21"));
}

Test:TimeFormat_WEEK_OF_YEAR_ZER() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEK_OF_YEAR_ZERO, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "22"));
}

Test:TimeFormat_WEEK_DAY_ZERO() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEK_DAY_ZERO, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "6"));
}

Test:TimeFormat_WEEK_OF_YEAR_ALT() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, WEEK_OF_YEAR_ALT, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "22"));
}

// Test:TimeFormat_LOCALE_DATE() {
//     new
//         Timestamp:ts = Timestamp:1527929232,
//         output[256];

//     TimeFormat(ts, LOCALE_DATE, output);
//     printf("- output: '%s'", output);
//     ASSERT(!strcmp(output, "06/02/18"));
// }

// Test:TimeFormat_LOCALE_TIME() {
//     new
//         Timestamp:ts = Timestamp:1527929232,
//         output[256];

//     TimeFormat(ts, LOCALE_TIME, output);
//     printf("- output: '%s'", output);
//     ASSERT(!strcmp(output, "08:47:12"));
// }

Test:TimeFormat_YEAR_ABV() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, YEAR_ABV, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "18"));
}

Test:TimeFormat_YEAR() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, YEAR, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "2018"));
}

Test:TimeFormat_UTC_OFFSET() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, UTC_OFFSET, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "+0000"));
}

Test:TimeFormat_TIME_ZONE_ABV() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, TIME_ZONE_ABV, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "UTC"));
}

Test:TimeFormat_PERCENTAGE() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, PERCENTAGE, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "%"));
}

Test:TimeFormat_HUMAN_DATE() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, HUMAN_DATE, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "02/06/18"));
}

Test:TimeFormat_ISO6801_TIME() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, ISO6801_TIME, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "08:47:12"));
}

Test:TimeFormat_ISO6801_DATE() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, ISO6801_DATE, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "2018-06-02"));
}

Test:TimeFormat_ISO6801_FULL_UTC() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, ISO6801_FULL_UTC, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "2018-06-02T08:47:12Z"));
}

Test:TimeFormat_ISO6801_FULL_LOC() {
    new
        Timestamp:ts = Timestamp:1527929232,
        output[256];

    TimeFormat(ts, ISO6801_FULL_LOCAL, output);
    printf("- output: '%s'", output);
    ASSERT(!strcmp(output, "2018-06-02T08:47:12"));
}

Test:TimeParse_ISO6801_FULL_UTC() {
    new Timestamp:ts, ret;
    ret = TimeParse("2018-06-02T08:47:12Z", ISO6801_FULL_UTC, ts);
    printf("- output: %d: %d", ret, _:ts);
    ASSERT(ts == Timestamp:1527929232);
}

Test:TimeParse_Invalid() {
    new
        year = 1997,
        month = 3,
        day = 2,
        ret,
        Timestamp:seconds,
        Seconds:agetime;

    TimeParse(sprintf("%i%i%i", year, month, day), "%Y%m%d", seconds);
    agetime = Now() - seconds;

    printf("- output: %d: %d agetime: %d", ret, _:seconds, _:agetime);
    ASSERT(seconds == Timestamp:0);
}

Test:TimestampDifference() {
    new
        Timestamp:future = Timestamp:1527932832,
        Timestamp:past = Timestamp:1527929232;
    
    new Seconds:difference = future - past;
    ASSERT(difference == Seconds:3600);
}

Test:SecondsOperators() {
    new
        Timestamp:t = Timestamp:1527929232,
        Seconds:d = Seconds:3600;

    t += d;
    ASSERT(t == Timestamp:1527932832);

    t -= d;
    ASSERT(t == Timestamp:1527929232);

    t++;
    ASSERT(t == Timestamp:1527929233);

    t--;
    ASSERT(t == Timestamp:1527929232);
}

Test:MinutesOperators() {
    new
        Timestamp:t = Timestamp:1527929232,
        Minutes:d = Minutes:5;

    t += d;
    ASSERT(t == Timestamp:1527929532);

    t -= d;
    ASSERT(t == Timestamp:1527929232);

    ASSERT((Timestamp:1527929532 - Timestamp:1527929232) == Seconds:300);
}

Test:HoursOperators() {
    new
        Timestamp:t = Timestamp:1527929232,
        Hours:d = Hours:3;

    t += d;
    ASSERT(t == Timestamp:1527940032);

    t -= d;
    ASSERT(t == Timestamp:1527929232);

    ASSERT((Timestamp:1527940032 - Timestamp:1527929232) == Seconds:10800);
}

Test:DaysOperators() {
    new
        Timestamp:t = Timestamp:1527929232,
        Days:d = Days:3;

    t += d;
    ASSERT(t == Timestamp:1528188432);
    printf("- output: %d", _:t);

    t -= d;
    ASSERT(t == Timestamp:1527929232);

    ASSERT((Timestamp:1527940032 - Timestamp:1527929232) == Seconds:10800);
}
