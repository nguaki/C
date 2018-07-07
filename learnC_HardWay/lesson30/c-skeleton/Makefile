CC = gcc

#################################################################
# Specify compilation flags.
#################################################################
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
#CFLAGS=-g -Wall -std=gnu99 -Isrc -DNDEBUG $(OPTFLAGS)

#################################################################
# Specify linking flags.
#################################################################
LIBS=-ldl $(OPTLIBS)

#################################################################
#Can specify PREFIX from command line.
#e.g. make PREFIX=/usr/local2 all
#     If it is not specified, the default value is /usr/local.
#################################################################
PREFIX?=/usr/local

###############################################################
#Source files are from src/ and its children directories.
###############################################################
SOURCES=$(wildcard src/**/*.c src/*.c)

###############################################################
#Identify object files.
###############################################################
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

###############################################################
#Specify test directory.
###############################################################
TEST_DIR=tests

###############################################################
#Specify test source code.
###############################################################
TEST_SRC=$(wildcard $(TEST_DIR)/*_tests.c)

###############################################################
#Obtain executables.
###############################################################
TEST_EXE=$(patsubst %.c,%,$(TEST_SRC))

###############################################################
#Specify build directory.
###############################################################
BUILD_DIR=build

###############################################################
#Specify static library.
###############################################################
TARGET=$(BUILD_DIR)/libYOUR_LIBRARY.a

###############################################################
#Specify shared library.
###############################################################
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

###############################################################
# This is one step which builds and tests.
###############################################################
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -ldl -Wextra $(OPTFLAGS)
dev: all

###############################################################
#Build static library.
###############################################################
$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	@echo  "Beginning building $(TARGET)"
	ar rcs $@ $(OBJECTS)
	ranlib $@
	@echo  "End building $(TARGET)"

###############################################################
#Build shared library.
###############################################################
$(SO_TARGET): $(TARGET) $(OBJECTS)
	@echo  "Start building $(SO_TARGET)"
	$(CC) -shared -o $@ $(OBJECTS) $(LIBS)
	@echo  "End building $(SO_TARGET)"

###############################################################
#Create directories if these don't exist.
###############################################################
build:
	@mkdir -p build
	@mkdir -p bin

###############################################################
# The Unit Tests
# runtests.sh will run all test executables.
###############################################################
TEST_CFLAGS=-Wall -g -Isrc -DNDEBUG $(OPTFLAGS)
.PHONY: tests
#tests: CFLAGS += $(SO_TARGET) $(LIBS)
tests: $(TEST_EXE)
	@echo "start compiling for tests"
	sh ./tests/runtests.sh

$(TEST_DIR)/%: $(TEST_DIR)/%.c
	$(CC) $(TEST_CFLAGS) $< -ldl -o $@
	
# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TEST_EXEC)
	rm -f tests/tests.log 
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
		|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true

help:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TEST_SRC: $(TEST_SRC)"
	@echo "TEST_EXEC: $(TEST_EXEC)"
	@echo "TARGET: $(TARGET)"
	@echo "SO_TARGET: $(SO_TARGET)"
