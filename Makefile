# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 15:45:10 by gade-alm          #+#    #+#              #
#    Updated: 2022/12/29 19:15:51 by gade-alm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(SRCS_DIR)/main.c \
			$(SRCS_DIR)/ft_atoi.c \
			$(SRCS_DIR)/new_philo.c \
			$(SRCS_DIR)/prints.c \
			$(SRCS_DIR)/get_time.c \
			$(SRCS_DIR)/philo_jobs.c \
			$(SRCS_DIR)/checkers.c \
			
SRCS_DIR = srcs

OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR = objs

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread -I includes -g -fsanitize=thread

RM		= rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@
	
clean: 
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all