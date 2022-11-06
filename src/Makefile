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

QMAKE_PATH = ./usr/local/lib/qmake
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs --coverage
LCHECK = -lcheck

SOURCES_TEST:= $(wildcard parser/*.c)

OBJ_GCOV_DIR := obj_gcov
OBJECTS_GCOV := $(addprefix obj_gcov/, $(notdir $(SOURCES_TEST:.c=.o)))
HEADER = parser/s21_parser.h

APP = build/qtViewer.app
MK = mkdir -p

all:  install run

install:
	sh build/build.sh qmake

run:
	build/Viewer/qtViewer.app/Contents/MacOS/qtViewer

uninstall:
	@rm -rf build/Viewer

dist:
	sh dist/dist.sh

dvi:
	doxygen doxygen/Doxyfile
	@mv html doxygen
	open doxygen/html/index.html

clean_dvi:
	@rm -rf doxygen/html

clean_dist:
	@rm -rf dist/3D_viewer_dist.tar
	@rm -rf dist/3D_viewer_dist

test: parser/tests/test.c $(HEADER) $(OBJECTS_GCOV)
	$(CC) $< $(OBJ_GCOV_DIR)/*.o -o $@ $(LCHECK) $(LDFLAGS) $(GCOVFLAGS)
	- ./test
	gcovr	-r	.	--html	--html-details	-o	coverage_report.html
	rm	-rf	*.o	*.out	*.gcno	*.gcna	*gcda
	mkdir report
	mv *.html *.css ./report

$(OBJECTS_GCOV): $(OBJ_GCOV_DIR)%.o: parser%.c $(HEADER)
	@mkdir -p obj_gcov
	$(CC) -o $@ -c $< $(LDFLAGS) $(GCOVFLAGS)

clean:
	@rm -rf obj_gcov
	@rm -rf test *gcda *gcno
	@rm -rf out
	@rm -rf *.dSYM
	@rm -rf report

open gcov_report:
	open	./report/coverage_report.html

.PHONY: all install run uninstall dist dvi clean_dvi test clean
