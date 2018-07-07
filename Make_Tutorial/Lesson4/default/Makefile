TARGET = main

##################################################
#All source files reside on its parent directory.
##################################################
DIR  = ..

##################################################
#Retain all source files.
##################################################
SOURCE = $(wildcard $(DIR)/*.c)

##################################################
#Get its corresponding object files.
#Do not include directory path.
##################################################
OBJECT = $(notdir $(SOURCE:.c=.o))

CC = gcc
CFLAGS = -Wall -std=gnu99

##################################################
#Linking
#Note that there is one link.
##################################################
$(TARGET): $(OBJECT)
	$(CC) -o $@ $^

##################################################
#Compiling
#Note that each .c file has compile.
##################################################
%.o: $(DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

##################################################
# Utility 
##################################################
.PHONY: run help clean

run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET) $(OBJECT)
	
help:
	@echo "SOURCE = $(SOURCE)"
	@echo "OBJECT = $(OBJECT)"
