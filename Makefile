# My make file 

CC = gcc

.PHONY: clean

all: main

main: main.c
	@echo "Building main.c"
	${CC} -w $< -o $@ `pkg-config --cflags --libs gtk+-2.0`
	@echo "./main to run the application"

clean: 
	@rm -f main
	@echo "workarea sanitized, be happy!"
