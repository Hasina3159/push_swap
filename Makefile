NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = p.c push_swap.h r.c rr.c s.c utils_0.c push_swap.c

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	rm $(NAME)

fclean : clean

re : fclean all

.PHONY : all clean fclean re