
all: $(PROG) clean

$(PROG): main.o utils.o skiplist.o
	@gcc main.o data.o read.o write.o -lm -g -o $(PROG)

clean:
	@rm -rf core *.o *.gch

main.o:
	@gcc -c main.c -lm -g

data.o:
	@gcc -c data.c data.h -lm -g

read.o:
	@gcc -c read.c read.h -lm -g

write.o:
	@gcc -c write.c write.h -lm -g

run:
	@./$(PROG)

valgrind: all
	@valgrind --leak-check=full --track-origins=yes ./$(PROG)