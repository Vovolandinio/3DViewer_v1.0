### env
UNAME:=$(shell uname -s)

ifeq ($(UNAME), Linux)
D_ENV=__LINUX__
endif
ifeq ($(UNAME), Darwin)
D_ENV=__MAC_OS__
endif
### C
CC = gcc -g

GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs --coverage
LCHECK = -lcheck

SOURCES_TEST:= $(wildcard parser/*.c)

OBJ_GCOV_DIR := obj_gcov
OBJECTS_GCOV := $(addprefix obj_gcov/, $(notdir $(SOURCES_TEST:.c=.o)))
HEADER = parser/s21_parser.h

test: parser/tests/test.c $(HEADER) $(OBJECTS_GCOV)
	$(CC) $< $(OBJ_GCOV_DIR)/*.o -o $@ $(LCHECK) $(LDFLAGS) $(GCOVFLAGS)
	./$@
	@rm -f *tests*

$(OBJECTS_GCOV): $(OBJ_GCOV_DIR)%.o: parser%.c $(HEADER)
	@mkdir -p obj_gcov
	$(CC) -o $@ -c $<

clean:
	rm -rf obj_gcov
	rm -rf test *gcda *gcno
	rm -rf out
	rm -rf *.dSYM