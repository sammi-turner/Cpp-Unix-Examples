# C++ Examples

A [GNU make](https://en.wikipedia.org/wiki/Make_(software)) template for Linux and MacOS.

## To build

From the root directory, enter

```
make
```

## Useful shell aliases

```
alias run='./bin/main'
alias mar='make && ./bin/main'
```

to build and run the binary from the root directory.

## Source files

.cpp files go in the src directory.

## Header files

.h files go in the include directory.

Don't forget to use [include guards](https://en.wikipedia.org/wiki/Include_guard) on all headers.
