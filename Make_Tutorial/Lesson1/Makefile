#  Simple illustration of Makefile

#1


#target with dependencies
main: main.o led.o
	gcc -o main main.c led.c

#each object file with its dependency
main.o: main.c
	gcc -c main.c -o main.o
led.o: led.c
	gcc -c led.c -o led.o

#In case there are files called 'clean' or 'run' in the same directory, .PHONY declaration and definition
#allows make command to execute 'clean' or 'run' commands.
.PHONY: clean run

#By adding 'main', this allows makefile to execute #1 above which is to compile main.
#If there is no 'main', makefile will error out complaining that 'main' doesn't exists.
run: main
	./main

clean:
	rm -f main main.o led.o
