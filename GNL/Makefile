CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
get_next_line_utils.c \

B_SRC = get_next_line_bonus.c \
get_next_line_utils_bonus.c \

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

NAME = gnl.a
B_NAME = gnl_bonus.a

all: $(NAME)
	norminette

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ)
	@ar -rcs $(B_NAME) $(B_OBJ)
	@ar -rcs $(NAME) $(B_OBJ)

clean:
	@rm -f $(SRC:.c=.o) $(B_SRC:.c=.o)

fclean: clean
	@rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus