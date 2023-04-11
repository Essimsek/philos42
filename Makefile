CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LFLAGS = -pthread

SRCS = ./src/main.c ./src/utils.c ./src/error_handling.c ./src/checking_args.c \
		./src/create_philo.c ./src/init.c ./src/routines.c ./src/dead_check.c \
		./src/free.c

OBJS = $(SRCS:.c=.o)

NAME = philo

INCLUDE = -I./include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf ./src/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
