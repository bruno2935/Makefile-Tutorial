
#Compiler
CC=gcc
#Flags used
CFLAGS = -g -wall
#all .o files
OBJS = allocator.o memtest.o
#binaries to compile
BIN = main

#To compile the bin
all:$(BIN)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) - o main

%.o: %.compile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r main *.o *.dSYM