NAME = libAOC
EXE = exe.out
HEADER = includes/AOC.h
UTILS = utils/*.c
OBJECTS = *.o

run:
	@./a.out

d1: fclean
	@gcc -g $(HEADER) $(UTILS) srcs/d1.c
	@echo "Compiled 'Day 1, Exercise 1'"
	@./a.out

d2:
	@gcc -g $(HEADER) $(UTILS) srcs/d2.c
	@echo "Compiled 'Day 2, Exercise 1'"
	@./a.out

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "Objects cleared"

fclean: clean
	@/bin/rm -f $(NAME) a.out
	@echo "clean"

re: fclean run
.PHONY: run
