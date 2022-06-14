SRC = $(shell find src -name "*.c")

OBJ = $(SRC:.c=.o)

NAME = minishell

LIBFT = libft.a

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ)
	gcc  $(OBJ) -o $(NAME) -lreadline -LLibft/Libft/ -lft -Wall -Werror -Wextra

$(LIBFT):
	@make -C Libft/Libft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
