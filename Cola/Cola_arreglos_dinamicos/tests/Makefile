CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = ../src
TEST_SRC = test_stack.c
TEST_EXE = test_stack

all: $(TEST_EXE)

$(TEST_EXE): $(TEST_SRC) $(SRCDIR)/stack.c
	$(CC) $(CFLAGS) -o $(TEST_EXE) $(TEST_SRC) $(SRCDIR)/stack.c -lcheck

run: $(TEST_EXE)
	./$(TEST_EXE)

clean:
	rm -f $(TEST_EXE)