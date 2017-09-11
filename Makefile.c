#include <stdio.h>

# Rule to build a test executable
# DO NOT MODIFY
test: test.c functions.c
	$(CC) $(CFLAGS) $^ -o $@

# Rule to run a testing script and produce an output file
# DO NOT MODIFY
.PHONY: test-run
test-run: test test.py
	python3 test.py

# Rule to run *your* clean rule AND remove the test executable
.PHONY: really-clean
really-clean: clean
rm -fv test
