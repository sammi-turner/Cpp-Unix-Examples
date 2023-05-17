# C++ Examples

A [GNU make](https://en.wikipedia.org/wiki/Make_(software)) template for Linux and MacOS.

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
alias bar='make && ./build/main'
```

which will allow you to enter the command

```
bar
```

to build and run the binary from the root directory.

## Source files

.cpp files go in the src directory.

## Header files

.h files go in the include directory.

Don't forget to use [include guards](https://en.wikipedia.org/wiki/Include_guard) on all headers.
