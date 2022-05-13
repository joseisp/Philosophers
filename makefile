NAME = philo

FILES = main.c initial_error.c philo.h

all: $(NAME)

$(NAME):
		gcc -pthread $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all
