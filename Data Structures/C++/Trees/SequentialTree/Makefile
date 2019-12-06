PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = SequentialTree.o

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	SequentialTree

SequentialTree:	$(OBJS)
	$(CXX) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr SequentialTree $(OBJS)

	
	
	
##
## LinkedList Data Structure
##
## Author: Loay Wael
##
##
#
## Program Locations
#CXX = g++
#SRC_LOC = ../src
#OBJ_LOC = ./obj
##LIBS_LOC = ../lib
#
## Compiler Flags
#LIBS = -lm
#CFLAGS = -I$(SRC_LOC) -Wall -c -o
#LFALGS = -I$(SRC_LOC) $(LIBS) -Wall -o
#
## Included Declarations
#_DEPS = LinkedList.hpp
#DEPS = $(patsubst %,$(SRC_LOC)/%,$(_DEPS))
#
## Compiled Objects
#_OBJS = main.o LinkedList.o
#OBJS = $(patsubst %,$(OBJ_LOC)/%,$(_OBJS))
#
## Compiling Stage
#$(OBJ_LOC)/%.o: $(SRC_LOC)/%.cpp $(DEPS)
#	@echo "-----------------------------------"
#	@echo "Compiling the file $<"
#	@echo "-----------------------------------"
#	$(CXX) $(CFLAGS) $@ $< 
#
##Program Name
#PROG = run
#
## All Target
#all : $(PROG) 
#
## Linking Stage
#$(PROG) : $(OBJS)
#	@echo "-----------------------------------"
#	@echo "Creating the executable ($@)"
#	@echo "-----------------------------------"
#	$(CXX) $(LFALGS) $@ $^
#
#.PHONY : clean
#
#clean :
#	rm $(OBJ_LOC)/*.o *~ core
	