#######################################################################
# March 30, 17
#
# This makefile creates executables to test all methods in
# returning array.
#
#
#
#######################################################################

SOURCE = $(wildcard SOURCE/meth*.c)
EXEC = $(patsubst %.c, EXEC/%, $(notdir $(SOURCE)))

EXEC/%: SOURCE/%.c
	gcc $< -o $@

run: $(EXEC)
	EXEC/method1
	EXEC/method2
	EXEC/method3
	EXEC/method4
	EXEC/method5
	EXEC/method6
	EXEC/method7

help:
	@echo $(SOURCE)
	@echo $(EXEC)

clean:
	rm EXEC/*
