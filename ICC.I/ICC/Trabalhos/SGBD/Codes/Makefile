# Arquivo Makefile para compilação e execução do programa
PROG = sgbd
FLAGS = -Wall -Werror -lm -g

all: compile clean

compile:
	@gcc -c *.c *.h $(FLAGS)
	@gcc *.o $(FLAGS) -o $(PROG)

clean:
	@rm -rf core *.o *.gch

run:
	@./$(PROG)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(PROG)