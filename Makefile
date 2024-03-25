NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = src/push_swap.c src/ft_split.c src/ft_calloc.c src/free.c src/s.c src/utils_1.c src/utils_3.c src/p.c src/r.c src/rr.c src/utils_0.c src/utils_2.c src/error_check.c src/utils_sort.c src/utils_sort_2.c src/utils_sort_3.c src/sort_to_tab.c src/push_swap_1.c

SRCS_BONUS = srcs_bonus/ft_calloc.c srcs_bonus/get_next_line_utils.c srcs_bonus/rr.c srcs_bonus/cheker.c srcs_bonus/ft_split.c srcs_bonus/p.c srcs_bonus/s.c srcs_bonus/error_check.c  srcs_bonus/get_next_line.c srcs_bonus/push_swap.c srcs_bonus/utils_0.c srcs_bonus/free.c srcs_bonus/r.c srcs_bonus/utils_1.c

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) -g

all : $(NAME)

clean :
	rm $(NAME)

fclean : clean

re : fclean all

#Some small tests that i have found on StackOverflow and Github

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test50:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 50))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY : all clean fclean re
