NAME = push_swap

NAME_B = checker

SRC =	src/push_swap.c\
		src/ft_split.c\
		src/ft_lstnew.c\
		src/ft_atoi.c\
		src/ft_isdigit.c\
		src/ft_lstadd.c\
		src/commands/swap_push.c\
		src/commands/rotate.c\
		src/sorting.c\
		src/sorting_utils.c\
		src/utils.c

SRC_B =	src/ft_split.c\
		src/ft_lstnew.c\
		src/ft_atoi.c\
		src/ft_isdigit.c\
		src/ft_lstadd.c\
		src/commands/swap_push.c\
		src/commands/rotate.c\
		src/bonus/checker.c\
		src/bonus/ft_strncmp.c\
		src/bonus/get_next_line.c\
		src/utils.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

INCLUDE = includes/push_swap.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDE) -o $(NAME)
		
bonus: $(OBJ_B)
		$(CC) $(CFLAGS) $(OBJ_B) -I $(INCLUDE) -o $(NAME_B)
		
clean:
		$(RM) $(OBJ) $(OBJ_B)
		
fclean: clean
		$(RM) $(NAME) $(NAME_B)
		
re: fclean all

.PHONY:	all fclean clean re