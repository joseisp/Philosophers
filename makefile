NAME = philo

FILES += main.c initial_error.c philo.h declaration_init.c
FILES += free_philos.c utils.c

all: $(NAME)

$(NAME):
		gcc -pthread -g $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all
