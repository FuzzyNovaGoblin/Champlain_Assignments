CXX 		:= g++
CXXFLAGS := -std=c++17 -ggdb

BIN 		:= bin
SRC 		:= src
INCLUDE	:= include

LIBS   	:=
EXEC 		:= main

OBJ = $(SRC:.cc=.o)

all: $(BIN)/$(EXEC)

run: clean all
	# clear
	$(BIN)/$(EXEC)

$(BIN)/$(EXEC): $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@ $(LIBS)

clean:
		-rm $(BIN)/*