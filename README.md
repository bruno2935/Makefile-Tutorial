# Makefile-Tutorial

## This project will be used to training how to setup a build system using makefiles
## Target Name '$@ , Dependencies of the target $^

### The format is dependencies and then target name
Target_name : Dependencies
gcc  [dependencies] -o [target_name]
```Make
all : test.exe

test.exe : test1.o test2.o main.o
		gcc test1.o test2.o main.o test.exe
			
test1.o  : test1.c
		gcc -c test1.c -o test1.o

test2.o  : test2.c
		gcc -c test2.c -o test2.o

main.o: main.c
		gcc -c main.c -o main.o

clean :
	 	rm -rf *.o *.exe
```

Automatic Variables
1. `$@` - Replace with target name
 gcc  [dependencies] -o [ $@]
```Make
all : test.exe

test.exe : test1.o test2.o main.o
		gcc test1.o test2.o main.o $@
			
test1.o  : test1.c
		gcc -c test1.c -o $@

test2.o  : test2.c
		gcc -c test2.c -o $@

main.o: main.c
		gcc -c main.c -o $@

clean :
		rm -rf *.o *.exe
```

2. `$^` - Replace with all pre-requisites(without duplicate)
 gcc  [$^] -o [ $@]
```Make
all : test.exe

test.exe : test1.o test2.o main.o
		gcc $^ -o $@
			
test1.o  : test1.c
		gcc -c $^ -o $@

test2.o  : test2.c
		gcc -c $^ -o $@

main.o: main.c
		gcc -c $^ -o $@

clean :
		rm -rf *.o *.exe
```

2. `$<` - Replace first pre-requisite
 gcc  [$<] -o [ $@]
```Make
all : test.exe

test.exe : test1.o test2.o main.o
		gcc $^ -o $@
			
test1.o  : test1.c
		gcc -c $< -o $@

test2.o  : test2.c
		gcc -c $< -o $@

main.o: main.c
		gcc -c $< -o $@

clean :
		rm -rf *.o *.exe
```

3. `$+` - Replace with all pre-requisites (with duplicate)
 gcc  [$+] -o [ $@]
```Make
all : test.exe

test.exe : test1.o test2.o main.o
		gcc $^ -o $@
			
test1.o  : test1.c
		gcc -c $< -o $@

test2.o  : test2.c
		gcc -c $< -o $@

main.o: main.c
		gcc -c $< -o $@

clean :
		rm -rf *.o *.exe
```

3. `$?` - Replace only with newer pre-requisites
 gcc  [$+] -o [ $@]