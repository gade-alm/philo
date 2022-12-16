# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 15:45:10 by gade-alm          #+#    #+#              #
#    Updated: 2022/12/16 18:14:15 by gade-alm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/philo.c \
			srcs/ft_atoi.c \
			srcs/new_philo.c \
			srcs/prints.c \
			srcs/gettime.c \

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -pthread -g -fsanitize=thread

RM		= rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all