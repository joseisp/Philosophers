NAME = philo

FILES = main.c initial_error.c ft_atoi.c philo.h

all: $(NAME)

$(NAME):
		gcc -pthread -g $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all
