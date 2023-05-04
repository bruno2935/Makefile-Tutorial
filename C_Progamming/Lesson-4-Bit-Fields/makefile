#
#Compiler
CC=clang
#Flags used
CFLAGS =-g -Wall -o2
#Source dir
SRC = src
#Objects dir
OBJ = obj
#Greb all .c files
SRCS=$(wildcard $(SRC)/*.c)
# $(patsubst pattern,replacement,input)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
#binaries to compile
BINDIR=bin
BIN = $(BINDIR)/main
#zip the program
SUBMITENAME = project5.zip
#-----------------------------------------------------
#To compile the bin

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submit:
	$(RM) $(SUBMITENAME)
	zip $(SUBMITENAME) $(BIN).exe

run:$(BIN)
	./$(BIN)