
TARGET = main

##################################
# Specify directories.
##################################
SRC = src
BIN = bin
INC = inc

##################################
#Font coloring specification
##################################
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;33m
NC = \033[1;0m
##############################################################
#Get all .c files from src directory
##############################################################
SOURCE = $(wildcard $(SRC)/*.c)

##############################################################
#notdir means not to display directory.
#SOURCE:.c=.o means to replace suffix .c with .o
#patsubst means to substitute X with bin/X.
#The final output will look something like bin/xyz.o
##############################################################
OBJECT = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

CC = gcc

#Specify where include files reside.
CFLAGS = -Wall -I$(INC) -std=gnu99

##############################################################
#Link all object files from obj directory and create an executable which will be
#saved to bin/ directory.
##############################################################
$(BIN)/$(TARGET): $(OBJECT)
	@echo "$(RED) linking ... "
	$(CC) -o $@ $^

##############################################################
#Compile every c file from src directory and create its corresponding object files
#and save it to bin directory.
##############################################################
$(BIN)/%.o : $(SRC)/%.c
	@echo "$(BLUE) compiling ... "
	$(CC) $(CFLAGS) -c $< -o $@
	
	
.PHONY: help clean run

run: $(BIN)/$(TARGET)
	@echo "$(GREEN) running ... "
	$(BIN)/$(TARGET)

help:
	@echo "source: $(SOURCE)"
	@echo "object: $(OBJECT)"


clean:
	rm -f $(OBJECT) $(BIN)/$(TARGET)
