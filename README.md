# Oven Automation

A console application in C++ that simulates the control panel of a domestic oven:
start it, set temperature, timer, dish and fan mode, then read those settings back on a
later run.

Written for BLG-101 *Introduction to Algorithms and Programming* at Isparta University
of Applied Sciences, Faculty of Technology, Computer Engineering — first-year coursework
from the 2023–2024 autumn term.

## What it does

```
1  Start the oven   →  enter temperature, time, dish, fan on/off  →  stop
2  Show settings    →  read the last saved configuration back
```

Settings are held in a `struct` and written to `firinayarlari.dat` with `fstream`, so
they survive between runs. The interface loops on a menu until the user quits.

## Concepts it covers

- `struct` for grouping related fields
- File I/O with `fstream` for persistence between sessions
- `switch` / `do-while` menu loop
- Unbuffered key input via `getche()`
- Localisation with `setlocale` for Turkish output

## Building it

```bash
g++ src/oven-automation.cpp -o oven-automation
./oven-automation
```

> The source uses `<conio.h>`, which is MSVC/MinGW-specific — it builds on Windows out
> of the box. On Linux or macOS, replace `getche()` with `std::cin >> secim` and drop the
> `<conio.h>` include.

## A note on keeping this here

This is beginner coursework and I have deliberately not rewritten it. It is the earliest
code in my account, and leaving it untouched next to what I build now is a more honest
picture of the distance covered than quietly deleting it would be.

## Licence

MIT — see [LICENSE](LICENSE).
