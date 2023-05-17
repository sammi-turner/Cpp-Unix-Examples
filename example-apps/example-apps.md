# Example Apps

## To build

From the root directory, enter

```
make
```

## To run 

From the bin directory, enter

```
./main
```

## To build and run

Adding the following alias to your shell dotfile

```
alias foo='make && ./build/main'
```

which will allow you to enter the command

```
foo
```

to build and run the binary from the root directory.

## List editor

This app implements basic [CRUD operations](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) on lists, in addition to 'swap', 'copy', 'cut', 'paste', 'insert', 'load', 'save', and 'exit'.

To return to the main menu, simply enter a blank input.

## Yahtzee

A solitaire, command line version of the [famous dice game](https://en.wikipedia.org/wiki/Yahtzee).
