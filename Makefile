# launcher
CC = gcc
FILES = src/main.c src/bots.c
NAME = launcher
OUT = bin/$(NAME)
DEST = /usr/bin

build:
	$(CC) $(FILES) -o $(OUT)

install:
	make build
	cp -f $(OUT) $(DEST)/$(NAME)
	echo Successfully installed bot launcher.

uninstall:
	make build
	rm -f $(DEST)/$(NAME)
	echo Successfully uninstalled bot launcher.
