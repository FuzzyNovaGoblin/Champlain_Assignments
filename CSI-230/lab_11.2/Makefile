CXX 		 := g++
CXXFLAGS :=

BIN 		:= bin
SRC 		:= src
INCLUDE	:= include -I/usr/include/boost/python -I/usr/include/python3.8/

LIBS   	:= -lboost_program_options -lboost_python38 -lpython3.8
EXEC 		:= main

OBJ = $(SRC:.cc=.o)

all: $(BIN)/$(EXEC)

run: clean all
	clear
	$(BIN)/$(EXEC) --1 4 --2 2

$(BIN)/$(EXEC): $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE)  $^ -o $@ $(LIBS)
	cp $(SRC)/*.py $(BIN)

clean:
		-rm $(BIN)/*