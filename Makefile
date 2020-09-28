CC = gcc
FLAGS = -Wall -Wextra --pedantic

fp: fp.c
	$(CC) $(FLAGS) fp.c -o fp
