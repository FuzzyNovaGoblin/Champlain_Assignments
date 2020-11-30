CXX 		:= g++
CXXFLAGS := -std=c++17 -ggdb

BIN 		:= bin
SRC 		:= src
INCLUDE	:= include
LIB := lib

LIBS   	:=
EXEC 		:= pal_driver

SO_NAME := pal

LIB_INSTALL_DIR := /usr/lib
BIN_INSTALL_DIR := /usr/local/bin

all: $(LIB)/lib$(SO_NAME).so $(BIN)/$(EXEC)

run: clean all
	clear
	$(BIN)/$(EXEC)



$(LIB)/lib$(SO_NAME).so: $(SRC)/$(SO_NAME)/*.cpp
	$(CXX) -fPIC -c -Wall -I$(INCLUDE) $^ -o $@ $(LIBS)



$(BIN)/$(EXEC): $(SRC)/$(EXEC)/*.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@ -L$(LIB) -l$(SO_NAME)

clean:
		-rm $(BIN)/*
		-rm $(LIB)/*

install:
	cp $(LIB)/lib$(SO_NAME).so $(LIB_INSTALL_DIR)/
	cp $(BIN)/$(EXEC) $(BIN_INSTALL_DIR)/

remove:
	rm $(LIB_INSTALL_DIR)/lib$(SO_NAME).so
	rm $(BIN_INSTALL_DIR)/$(EXEC)