# For building CS 211 Homework 1
# You don’t need to edit this file, and you probably shouldn’t.

# The programs we can build
EXES       = overlapped test_circle

# C compiler and compiler flags
CC        ?= cc
CFLAGS     = -std=c11 -pedantic -Wall
CFLAGS    += -fsanitize=address,undefined
LDFLAGS    = -lm

# Default recipe builds both programs
all: $(EXES)

# Builds the test and runs it
test: test_circle
	./test_circle

# How to build the test program
test_circle: test/test_circle.o src/circle.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# How to build the client program
overlapped: src/overlapped.o src/circle.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# How to compile one .c file into a .o file
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

# Removes all the build products
clean:
	rm -f $(EXES) */*.o

# Targets that are not actually files we can build:
.PHONY: all test clean

# Dependencies (when the file on the right changes then the file
# on the left needs to be rebuilt)
src/circle.o: src/circle.h
src/overlapped.o: src/circle.h
test/test_circle.o: src/circle.h

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
