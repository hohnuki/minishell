NAME = minishell

srcs = $(wildcard ./*.c)

objs = $(srcs:.c=.o)

CC = cc

libft_path = ./libft/
libft_make = $(MAKE) -C $(libft_path)
libft_flag = -L$(libft_path) -lft

all: $(NAME)
$(NAME): $(objs)
	@$(libft_make)
	@cc -o $(NAME) $(objs) $(libft_flag) -lreadline

clean:
	@rm -rf *.o
	@rm -rf a.out

fclean: clean
	@$(libft_make) clean
	@rm -rf $(NAME)

re: fclean all

test: all
	@./minishell 2> /dev/null

debug: all
	./minishell

.PHONY: all clean fclean re test debug