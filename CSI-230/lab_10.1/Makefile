CXX 		:= g++
CXXFLAGS := -std=c++17 -ggdb -fsanitize=address

BIN 		:= bin
SRC 		:= src
INCLUDE	:= include

LIB   	:=
EXEC 		:= main

OBJ = $(SRC:.cc=.o)

all: $(BIN)/$(EXEC)

run: clean all
	clear
	$(BIN)/$(EXEC)

$(BIN)/$(EXEC): $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@ $(LIBS)

clean:
		-rm $(BIN)/*