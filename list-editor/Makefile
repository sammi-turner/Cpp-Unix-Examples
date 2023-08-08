CXX		  := g++
CXX_FLAGS := -std=c++20

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= -lncurses -lsqlite3
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
