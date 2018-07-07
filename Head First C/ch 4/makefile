#create Add.o object.
#command: make Add.o
# scene 1: Add.c timestamp is prior to Add.o timestamp.
# make Add.o
# make: `Add.o' is up to date.
# scene 2: Add.c timestamp is later than Add.o timestamp.
# make Add.o
# gcc -c Add.c
Add.o: Add.c
	gcc -c Add.c
Sub.o: Sub.c
	gcc -c Sub.c
Mul.o: Mul.c
	gcc -c Mul.c
Div.o: Div.c
	gcc -c Div.c
#simpleMath.c has main().
simpleMath.o: simpleMath.c simpleMath.h
	gcc -c simpleMath.c
#doMath is the executable.
#Scene 1:
#Time stamps of all object files are prior to the executable timestamp.
#dguai:~/workspace/Head First C/ch 4 $ make doMath
#make: `doMath' is up to date.
#Scene 2:
#Time stamp of any object files are later than executable timestamp.
#dguai:~/workspace/Head First C/ch 4 $ make doMath
#gcc Add.o Sub.o Mul.o Div.o simpleMath.o -o doMath
#Scene 3:
#Time stamp of a C file is later than executable timestamp.
#dguai:~/workspace/Head First C/ch 4 $ make doMath
#gcc -c Sub.c
#gcc Add.o Sub.o Mul.o Div.o simpleMath.o -o doMath

doMath: Add.o Sub.o Mul.o Div.o simpleMath.o
	gcc Add.o Sub.o Mul.o Div.o simpleMath.o -o doMath
