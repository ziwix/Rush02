CC=cc 
NAME=rush-02
SRCS=algorithm.c file.c list.c parsing.c rush.c string.c common.c validate.c
HEADER=rush.h string.h
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

.PHONY: fclean clean
