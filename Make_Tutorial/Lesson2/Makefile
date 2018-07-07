CC = gcc
CFLAGS = -Wall -std=gnu99
TARGET = main

####################################################
#SOURCE retains all files with .c prefix
####################################################
SOURCE = $(wildcard *.c)

####################################################
#OBJECT retains all .o files.
####################################################
OBJECT = $(SOURCE:.c=.o)

####################################################
#These statements also works!!!
#However, this does both compiling and linking.
#The following method seems to be better since
#whenever a source code changes, it forces to
#recompile in order to generate a new object.
#$(TARGET): $(SOURCE)
#	gcc -o $(TARGET) $(SOURCE) 
####################################################

####################################################
# Linking portion.
# $@ is short hand for $(TARGET)
# $^ is short hand for $(SOURCE)
####################################################
$(TARGET): $(OBJECT)
	@echo "Started linking ..."
	$(CC) $(CFLAGS) $^ -o $@  
	@echo "Finished linking ..."

####################################################
#Whenever a C file is renewed, it gets compiled and a new
#object file is created.
#$< is short hand for a .c file.
####################################################
%.o: %.c
	@echo "Started compiling ..."
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Finished compiling ..."

.PHONY: clean run help

####################################################
# Remove executable and object files.
####################################################
clean:
	rm -f $(TARGET) $(OBJECT)

####################################################
# If executable is missing, it compiles the program.
####################################################
run: $(TARGET)
	./$(TARGET)

#@ character disallows echoing.
help:
	@echo "James Makefile"
	@echo "TARGET = $(TARGET)"
	@echo "SOURCE = $(SOURCE)"
	@echo "OBJECT = $(OBJECT)"
