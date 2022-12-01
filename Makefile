NAME = libAOC
EXE = exe.out
HEADER = includes/AOC.h
UTILS = utils/*.c
OBJECTS = *.o

run:
	@./a.out

11: fclean
	@gcc -g $(HEADER) $(UTILS) srcs/d1.c
	@echo "Compiled 'Day 1, Exercise 1'!"
	@./a.out

21:
	@gcc -I $(HEADERS) -c srcs/d2.c -o $(EXE)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Compiled 'Day 2, Exercise 1'!"
	@./a.out

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "Objects are gone!"

fclean: clean
	@/bin/rm -f $(NAME) a.out
	@echo "All clean!"

re: fclean run
.PHONY: run
