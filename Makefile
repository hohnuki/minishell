NAME = minishell

srcs = $(wildcard ./*.c)

objs = $(srcs:.c=.o)

CC = cc

all: $(NAME)
$(NAME): $(objs)
	@cc -o $(NAME) $(objs) ./libft/libft.a -lreadline

clean:
	@rm -rf *.o
	@rm -rf a.out

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: all
	@./minishell 2> /dev/null

debug: all
	./minishell

.PHONY: all clean fclean re test debug