
#Compiler
CC=gcc
#Flags used
CFLAGS =-g -Wall
#all .o files
OBJS = allocator.o memtest.o
#binaries to compile
BIN = main
#zip the program
SUBMITENAME = project5.zip

#To compile the bin
all:$(BIN)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r main *.o *.dSYM

submit:
	$(RM) $(SUBMITENAME)
	zip $(SUBMITENAME) $(BIN).exe