[COLOR="#FF4700"][SIZE="7"][B]Chrono[/B][/SIZE][/COLOR]

[URL="https://github.com/Southclaws/pawn-chrono"][IMG]https://shields.southcla.ws/badge/sampctl-pawn--chrono-2f2f2f.svg?style=for-the-badge[/IMG][/URL]

A modern Pawn library for working with dates and times.

[COLOR="RoyalBlue"][SIZE="6"][B]Installation[/B][/SIZE][/COLOR]

Simply install to your project:

[CODE]
sampctl package install Southclaws/pawn-chrono
[/CODE]

Include in your code and begin using the library:

[CODE]
[COLOR="Blue"]#include <chrono>[/COLOR]
[/CODE]

[COLOR="RoyalBlue"][SIZE="6"][B]Usage[/B][/SIZE][/COLOR]

This library provides functions, constants string constants and functions for working with times and dates.

[COLOR="DeepSkyBlue"][SIZE="5"][B]Tags[/B][/SIZE][/COLOR]

Tags are important, you should avoid passing around bare integers as timestamp or duration values. Tagging your variables helps catch mistakes during compilation.

These tags are also used by this library to provide useful conversion functions between units of time.

[LIST]
[*][FONT="courier new"]Timestamp:[/FONT] A tag that indicates a cell contains a Unix timestamp.
[*][FONT="courier new"]Milliseconds:[/FONT] Cell contains milliseconds duration.
[*][FONT="courier new"]Seconds:[/FONT] Cell contains seconds duration.
[*][FONT="courier new"]Minutes[/FONT]: Cell contains minutes duration.
[*][FONT="courier new"]Hours[/FONT]: Cell contains hours duration.
[*][FONT="courier new"]Days[/FONT]: Cell contains days duration.
[*][FONT="courier new"]Weeks[/FONT]: Cell contains weeks duration.
[*][FONT="courier new"]Months[/FONT]: Cell contains months duration.
[*][FONT="courier new"]Years[/FONT]: Cell contains years duration.
[/LIST]

There also exists [FONT="courier new"]TIME_UNITS[/FONT] which is a macro for all time unit tags, this is useful if you write a function that accepts any unit of time - remember to use [FONT="courier new"]tagof[/FONT] for runtime checking!

[COLOR="DeepSkyBlue"][SIZE="5"][B]Constants[/B][/SIZE][/COLOR]

There are a set of constants that follow the naming convention:

[FONT="courier new"]UnitInUnits[/FONT]

This includes:

[FONT="courier new"]SecondInMilliseconds[/FONT]

Going all the way up to

[FONT="courier new"]YearInDays[/FONT]

For expressive conversions between units. For example, to get [FONT="courier new"]5[/FONT] minutes in seconds, you can simple do:

[CODE]
[COLOR="Blue"]new[/COLOR] Seconds:s = Seconds:([COLOR="Purple"]5[/COLOR] * _:MinuteInSeconds);
[/CODE]

See the source code for all the unit constants.

[COLOR="DeepSkyBlue"][SIZE="5"][B]Natives[/B][/SIZE][/COLOR]

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]Now[/FONT][/SIZE][/COLOR]

A wrapper around [FONT="courier new"]gettime()[/FONT] that returns a [FONT="courier new"]Timestamp:[/FONT] tagged value for more type-safe code.

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]TimeFormat[/FONT][/SIZE][/COLOR]

A formatting function that takes a [FONT="courier new"]Timestamp:[/FONT] with a format string and outputs a formatted time string using the standard C/++ specifiers (like [FONT="courier new"]%Y[/FONT] for 4-digit year, [FONT="courier new"]%m[/FONT] for month, etc.)

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]TimeParse[/FONT][/SIZE][/COLOR]

A parser for strings containing dates and times that uses the C/++ specifiers to perform the reverse of [FONT="courier new"]TimeFormat[/FONT].

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]DurationParse[/FONT][/SIZE][/COLOR]

Parses duration strings and outputs their values in milliseconds, for example:

[LIST]
[*][FONT="courier new"]5ms[/FONT] > [FONT="courier new"]5[/FONT]
[*][FONT="courier new"]5s[/FONT] > [FONT="courier new"]5000[/FONT]
[*][FONT="courier new"]10m[/FONT] > [FONT="courier new"]600000[/FONT]
[*][FONT="courier new"]3h[/FONT] > [FONT="courier new"]10800000[/FONT]
[*][FONT="courier new"]1d[/FONT] > [FONT="courier new"]86400000[/FONT]
[*][FONT="courier new"]8m5s[/FONT] > [FONT="courier new"]485000[/FONT]
[*][FONT="courier new"]1d3h10m5s5ms[/FONT] > [FONT="courier new"]97805005[/FONT]
[/LIST]

[COLOR="DeepSkyBlue"][SIZE="5"][B]Operators[/B][/SIZE][/COLOR]

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]Seconds:operator-(Timestamp:future, Timestamp:past)[/FONT][/SIZE][/COLOR]

Casts timestamp difference to [FONT="courier new"]Seconds:[/FONT] for usage in duration-based functions.

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]Timestamp:operator+(Timestamp:t, T:d)[/FONT][/SIZE][/COLOR]

Where [FONT="courier new"]T[/FONT] is one of [FONT="courier new"]Seconds[/FONT], [FONT="courier new"]Minutes[/FONT], [FONT="courier new"]Hours[/FONT] or [FONT="courier new"]Days[/FONT].

For example:

[CODE]
[COLOR="Blue"]new[/COLOR]
    Timestamp:t = Timestamp:[COLOR="Purple"]1527929232[/COLOR],
    Minutes:d = Minutes:[COLOR="Purple"]5[/COLOR];

t += d;
[COLOR="Green"]// t is now 1527929532, aka advanced by 5 minutes, aka advanced by 300 seconds[/COLOR]
[/CODE]

Because [FONT="courier new"]d[/FONT] is tagged as [FONT="courier new"]Minutes[/FONT], when it’s added to [FONT="courier new"]t[/FONT] with [FONT="courier new"]+=[/FONT], it doesn’t just add the integer [FONT="courier new"]5[/FONT], it adds the seconds value of 5 minutes, which is 300.

[COLOR="RoyalBlue"][SIZE="6"][B]Testing[/B][/SIZE][/COLOR]

To run unit tests for Windows first build the plugin using Visual Studio, then:

[CODE]
make test-windows
[/CODE]

To build and run tests for Linux on Windows, make sure you have Docker installed and run:

[CODE]
make build-linux
make test-linux
[/CODE]

This simply builds the plugin in a Docker container then tests it with sampctl using the [FONT="courier new"]--container[/FONT] flag to run it in a Linux container.

