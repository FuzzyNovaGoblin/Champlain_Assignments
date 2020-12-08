CXX 		:= g++
CXXFLAGS := -std=c++17 `pkg-config gtkmm-3.0 --cflags --libs` 

BIN 		:= bin
SRC 		:= src
INCLUDE	:= include
LIB := lib

LIBS   	:=
EXEC 		:= fuzy-calc


LIB_INSTALL_DIR := /usr/lib
BIN_INSTALL_DIR := /usr/local/bin

# SRCDIR := src
# BUILDDIR := build
# TARGET := bin/runner

# SRCEXT := cpp
# SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
# CFLAGS := -std=c++17 -ggdb `pkg-config --cflags --libs gtk+-3.0`

INC := -I include

# all: $(LIB)/lib$(SO_NAME).so
all: $(BIN)/$(EXEC)

run: clean all
	clear
	$(BIN)/$(EXEC)


# $(LIB)/lib$(SO_NAME).so: $(SRC)/$(SO_NAME)/*.cpp
# 	$(CXX) $(CFLAGS) -I$(INCLUDE) $^ -o $@ $(LIBS)

$(BIN)/$(EXEC): $(SRC)/*.c*
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@ -L$(LIB)

clean:
		-rm $(BIN)/*
		-rm $(LIB)/*
