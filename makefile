
COMPILIER=g++

CFLAGS=-g -Wall -std=c++0x

LDFLAGS=

HEADERS= include/basic_types.h	\
	include/bmpio.h	\
	include/basic_geometry.h	\
	include/drawer.h	

SOURCES= main.cpp	\
	lib/basic_geometry.cc 	\
	lib/bmpio.cc	

EXECUTABLE=main

all: $(SOURCES) $(HEADERS)
	$(COMPILIER) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
