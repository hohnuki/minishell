NAME = minishell

srcs = $(wildcard ./*.c) \
	$(wildcard ./debug/*.c) \
	$(wildcard ./env/*.c) \
	$(wildcard ./exec/*.c) \
	$(wildcard ./lexer/*.c) \
	$(wildcard ./parser/*.c)

objs = $(srcs:.c=.o)

CC = cc
# CFLAGS = -Wall -Werror -Wextra #しばらく不要

libft_path = ./libft/
libft_make = $(MAKE) -C $(libft_path)
libft_flag = -L$(libft_path) -lft

all: $(NAME)
$(NAME): $(objs)
	@$(libft_make)
	@cc -o $(NAME) $(objs) ./libft/libft.a -lreadline

clean:
	rm -rf *.o
	rm -rf a.out
	rm -rf ./debug/*.o
	rm -rf ./env/*.o
	rm -rf ./exec/*.o
	rm -rf ./lexer/*.o
	rm -rf ./parser/*.o

fclean: clean
	@$(libft_make) clean
	@rm -rf $(NAME)


re: fclean all

test: all
	@./minishell 2> /dev/null

debug: all
	@./minishell

tdd: all
	@cd tests && bash ./basic_tester.sh 2>/dev/null

.PHONY: all clean fclean re test debug tdd
