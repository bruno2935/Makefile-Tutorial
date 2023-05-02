
#Compiler
CC=gcc
#Flags used
CFLAGS =-g -Wall
#Source dir
SRC = src
#Objects dir
OBJ = obj
#Greb all .c files
SRCS=$(wildcard $(SRC)/*.c)
# $(patsubst pattern,replacement,input)
OBJ = $(patsubst $(SRCS)/%.c, $(OBJ)/%.o, $(SRCS))

#all .o files
OBJS = obj/allocator.o obj/memtest.o
#binaries to compile
BIN = bin/main
#zip the program
SUBMITENAME = project5.zip

#To compile the bin
all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

obj/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r bin/* obj/*

submit:
	$(RM) $(SUBMITENAME)
	zip $(SUBMITENAME) $(BIN).exe