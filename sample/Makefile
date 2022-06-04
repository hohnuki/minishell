NAME = ease

srcs = $(wildcard ./*.c)
objs = $(srcs:.c=.o)

CC = cc

.PHONY: all
all: $(NAME)
$(NAME): $(objs) 
	cc -o $(NAME) $(objs) -lreadline

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf a.out
.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: all
	@./ease

