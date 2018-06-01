# Chrono

[![GitHub](https://shields.southcla.ws/badge/sampctl-pawn--chrono-2f2f2f.svg?style=for-the-badge)](https://github.com/Southclaws/pawn-chrono)

A modern Pawn library for working with dates and times.

**Not Finished Yet!**

This is merely a proposal for an API at the moment.

## Installation

Simply install to your project:

```bash
sampctl package install Southclaws/pawn-chrono
```

Include in your code and begin using the library:

```pawn
#include <chrono>
```

## Usage

The proposed API is:

### Tags

* `Timestamp:`: A tag that indicates a cell contains a Unix timestamp.
* `Milliseconds:`: Cell contains milliseconds duration.
* `Seconds:`: Cell contains seconds duration.
* `Minutes`: Cell contains minutes duration.
* `Hours`: Cell contains hours duration.
* `Days`: Cell contains days duration.
* `Weeks`: Cell contains weeks duration.
* `Months`: Cell contains months duration.
* `Years`: Cell contains years duration.

### Constants

There are a set of constants that follow the naming convention:

`UnitInUnits`

This includes:

`SecondInMilliseconds`

Going all the way up to

`YearInDays`

For expressive conversions between units.

### Natives

#### `Now`

A wrapper around `gettime()` that returns a `Timestamp:` tagged value for more
type-safe code.

#### `TimeFormat`

A formatting function that takes a `Timestamp:` with a format string and outputs
a formatted time string using the standard C/++ specifiers (like `%Y` for
4-digit year, `%m` for month, etc.)

#### `TimeParse`

A parser for strings containing dates and times that uses the C/++ specifiers to
perform the reverse of `TimeFormat`.

#### `TimeAdd`

Adds a duration to the specified timestamp. Also overloads the += and +
operators for `Timestamp:` and `Duration:`.

### Helper Functions

There will also be a set of helper functions and maybe macros for conversions
between units.

There will also be a set of overloaded operators for conversions between units.
