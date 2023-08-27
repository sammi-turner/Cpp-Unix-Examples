# Unix C++ Examples

Small example programs for MacOS and Linux.

<br>

## Dependency

[Ncurses](https://en.wikipedia.org/wiki/Ncurses) (this library is not available natively on Windows).

<br>

## To build

```
g++ *.cpp -std=c++14 -lncurses
```

<br>

## To run the binary

```
./a.out
```

<br>

## To build and run the binary

```
g++ *.cpp -std=c++14 -lncurses && ./a.out
```

<br>

## List editor

This app implements basic [CRUD operations](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) on lists, in addition to 'swap', 'copy', 'cut', 'paste', 'insert', 'load', 'save', and 'exit'.

To return to the main menu, simply enter a blank input.

<br>

## Yahtzee

A solitaire, command line version of the [famous dice game](https://en.wikipedia.org/wiki/Yahtzee).

<br>

## Utils

A collection of utility functions to reduce boilerplate.