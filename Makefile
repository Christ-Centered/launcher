# launcher
CC = gcc
FILES = src/main.c src/bots.c
NAME = launcher
OUT = bin/$(NAME)

build:
	$(CC) $(FILES) -o $(OUT)