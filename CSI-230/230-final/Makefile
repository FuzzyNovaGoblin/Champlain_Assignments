CXX 		:= g++
CXXFLAGS := -std=c++17 -ggdb -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cloudproviders -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -I/usr/include/at-spi-2.0 -pthread -lgtk-3 -lgdk-3 -lz -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0

BIN 		:= bin
SRC 		:= src
INCLUDE	:= include
LIB := lib

LIBS   	:=
EXEC 		:= runner

SO_NAME :=

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

$(BIN)/$(EXEC): $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@ -L$(LIB)

clean:
		-rm $(BIN)/*
		-rm $(LIB)/*
