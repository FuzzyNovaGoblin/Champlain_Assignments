CXX 		:= g++
CXXFLAGS := -std=c++17 -Wall `pkg-config gtkmm-3.0 --libs --cflags` `pkg-config --cflags --libs libqalculate`  -Iinclude

BIN 		:= bin

VPATH = src:include

SRCDIR 		:= src
sosrc := FuzCalcWin.cc FuzCalcApp.cc
MAINSRC 		:= $(SRCDIR)/main.cpp
sobjs 		:= $(patsubst %.cc,%.so,$(sosrc))
SO_NAMES 		:= $(patsubst %.cc,%,$(sosrc))

INCLUDE	:= -Iinclude
LIB := lib

LIBS   	:=
EXEC 		:= FuzCalc


LIB_INSTALL_DIR := /usr/lib
BIN_INSTALL_DIR := /usr/local/bin




all: $(foreach sob, $(sobjs),  $(LIB)/lib$(sob)) $(BIN)/$(EXEC)

run: clean all
	clear
	$(BIN)/$(EXEC)



$(LIB)/libFuzCalcWin.so: $(SRCDIR)/FuzCalcWin.cc
	$(CXX) $(CXXFLAGS) -fPIC -c  $(INCLUDE) $^ -o $@ -L$(LIB)

$(LIB)/libFuzCalcApp.so: $(SRCDIR)/FuzCalcApp.cc
	$(CXX) $(CXXFLAGS) -fPIC -c  $(INCLUDE) $^ -o $@ -L$(LIB)

$(BIN)/$(EXEC): $(MAINSRC)
	$(CXX)  $(CXXFLAGS) $(INCLUDE)  $^ -o $@ -L$(LIB) $(foreach libso, $(SO_NAMES),-l$(libso) )

clean:
		-rm $(BIN)/*
		-rm $(LIB)/*

install: all
	cp $(foreach sob, $(sobjs),  $(LIB)/lib$(sob)) $(LIB_INSTALL_DIR)/
	cp $(BIN)/$(EXEC) $(BIN_INSTALL_DIR)/

remove:
	rm $(foreach sob, $(sobjs),  $(LIB_INSTALL_DIR)/lib$(sob))
	rm $(BIN_INSTALL_DIR)/$(EXEC)