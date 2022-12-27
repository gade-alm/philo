# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 15:45:10 by gade-alm          #+#    #+#              #
#    Updated: 2022/12/27 17:34:00 by gade-alm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/philo.c \
			srcs/ft_atoi.c \
			srcs/new_philo.c \
			srcs/prints.c \
			srcs/gettime.c \

SRCS_DIR = srcs

OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR = objs

NAME	= philo

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -pthread -g -fsanitize=thread

RM		= rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			mkdir -p $(@D)
			$(CC) $(FLAGS) -c $< -o $@
	
clean: 
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all