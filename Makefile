# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 19:45:11 by jinacio-          #+#    #+#              #
#    Updated: 2022/05/25 21:15:13 by jinacio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -pthread -g

SRCDIR = src
OBJDIR = obj

FILES += checking.c declaration_init.c free_philos.c
FILES += initial_error.c utils.c philo.h
FILES += main.c routine.c philo.h

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ -I./src

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
