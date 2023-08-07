# Ncurses Template

An ncurses project template for MacOS and Linux.

## To build

From the root directory, enter

```
make
```

## Useful shell aliases

To run the binary.

```
alias run='./bin/main'
```

To build and run the binary.

```
alias mar='make && ./bin/main'
```

## Source files

.cpp files go in the src directory.

## Header files

.h files go in the include directory.

Don't forget to use [include guards](https://en.wikipedia.org/wiki/Include_guard) on all headers.

## List editor

This app implements basic [CRUD operations](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) on lists, in addition to 'swap', 'copy', 'cut', 'paste', 'insert', 'load', 'save', and 'exit'.

To return to the main menu, simply enter a blank input.

## Yahtzee

A solitaire, command line version of the [famous dice game](https://en.wikipedia.org/wiki/Yahtzee).
