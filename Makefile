NAME = push_swap
NAME2 = checker
SRC = ./src/func_lists.c ./src/func_lists2.c ./src/func_lists3.c ./src/func_lists4.c ./src/func_process.c ./src/sorts.c  ./src/func_lists5.c pushik.c func_bonus1.c func_bonus2.c ./src/sorts2.c  ./src/sorts3.c 
SRC2 = ./src/func_lists.c ./src/func_lists2.c ./src/func_lists3.c ./src/func_lists4.c ./src/func_process.c ./src/sorts.c  ./src/func_lists5.c checker.c ./get_next_line/* func_bonus1.c func_bonus2.c \
		 ./src/sorts2.c  ./src/sorts3.c checker2.c checker3.c

HEADER = push_swap.h
HEADER2 = get_next_line.h
CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME):
	${CC} ${FLAGS} $(SRC) -o $(NAME)
%.o: %.		$(HEADER)
	${CC} ${FLAGS} $(SRC) -o $(NAME)

bonus: $(NAME2)

$(NAME2):
	${CC} ${FLAGS} $(SRC2) -o $(NAME2)
%.o: %.		$(HEADER2)
	${CC} ${FLAGS} $(SRC) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re 
