#######################################
#compilation specification
#######################################
CC = g++
CFLAG = -I$(BOWL_DIR)/include 


#######################################
#Directory specification
#######################################
BOWL_DIR = BowlFunctions
BOWL_OBJ_DIR = Obj
TEST_DIR = TEST
TEST_EXE_DIR = EXE

#######################################
#Obtain all source file names.
#######################################
BOWL_SOURCES=$(wildcard $(BOWL_DIR)/*.c)
####################################################################################
#For each source file(without directory name), create its corresponding object name
#and prepend directory path (e.g.   BowlFunctions/EXE/xyz.o 
####################################################################################
BOWL_OBJECTS= $(patsubst %, $(BOWL_DIR)/$(BOWL_OBJ_DIR)/%, $(notdir $(BOWL_SOURCES:.c=.o)))

#######################################
#Obtain all source file names for tests.
#######################################
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
####################################################################################
#For each source file(without directory name), create its corresponding executable name
#and prepend directory path (e.g.   TEST/EXE/xyz 
####################################################################################
TEST_EXE = $(patsubst %.c, $(TEST_DIR)/$(TEST_EXE_DIR)/%, $(notdir $(TEST_SRC)))

#######################################
# Linking all objects.
# $^ -- implies all objects.
#######################################

#######################################################################
# Target #2
# Compiling and linking all source for testing.
# $< -- implies all source code.
#
#The target 'run' will execute this taget if
#there is a missing executable.
#
#This target will in turn execute compilation of objects
#if any objects are missing.
#This target has dependency on target #3.
#######################################################################
$(TEST_DIR)/$(TEST_EXE_DIR)/%:$(TEST_DIR)/%.c $(BOWL_OBJECTS)   #This line forced remove of all object files.
#$(TEST_EXE):$(TEST_SRC) $(BOWL_OBJECTS)      #This compiled just the first test code.
	$(CC)  $< $(BOWL_OBJECTS) -o $@ 

#######################################################################
# Target #3
# Compiling all source for bowling functions.
#######################################################################
#$(BOWL_OBJECTS): $(BOWL_DIR)/%.c       #This line didn't work.
$(BOWL_DIR)/$(BOWL_OBJ_DIR)/%.o: $(BOWL_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAG)

.PHONY: run clean help

######################################################################################################################################
# Target #1.
# Target is as follows:
# TEST_EXE:  TEST/EXE/runTest1  TEST/EXE/runTest2  TEST/EXE/runTest3  TEST/EXE/runTest4  TEST/EXE/runTestOthers  TEST/EXE/runTest_Angela
# This target has dependencies on Target #2.
######################################################################################################################################
run: $(TEST_EXE)
	sh ./$(TEST_DIR)/$(TEST_EXE_DIR)/testScript.sh
	@echo "Exit running"

######################################################################################################################################
# The below statement stops the auto removal of all object files.
# rm BowlFunctions/Obj/PrintScore.o BowlFunctions/Obj/setScore.o BowlFunctions/Obj/initialize.o 
#      BowlFunctions/Obj/BowlFunctions.o BowlFunctions/Obj/isStrike.o BowlFunctions/Obj/isSpare.o
######################################################################################################################################
.PRECIOUS: $(BOWL_DIR)/$(BOWL_OBJ_DIR)/%.o

#Debugging statements
help:
	@echo "BOWL_SOURCES: $(BOWL_SOURCES)"
	@echo "BOWL_OBJECTS: $(BOWL_OBJECTS)"
	@echo "TEST_SRC: $(TEST_SRC)"
	@echo "TEST_EXE: $(TEST_EXE)"

clean:
	rm $(TEST_DIR)/$(TEST_EXE_DIR)/runTest* $(BOWL_DIR)/$(BOWL_OBJ_DIR)/*.o
