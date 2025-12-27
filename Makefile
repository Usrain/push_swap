# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malebrun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 21:24:53 by malebrun          #+#    #+#              #
#    Updated: 2025/12/27 19:55:23 by malebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADER = sources/push_swap.h
SOURCESFOLDER = sources
OBJECTFOLDER = obj
SOURCES = cost_to_place.c \
		is.c \
		lissort.c \
		sort.c \
		utils.c \
		ft_atoi.c \
		lisarr.c \
		node.c \
		push.c \
		push_b.c \
		rotate.c \
		strutils.c \
		index.c \
		parser.c \
		push_swap.c \
		rrotate.c \
		swap.c

SRCS = $(addprefix $(SOURCESFOLDER)/, $(SOURCES))
OBJS = $(addprefix $(OBJECTFOLDER)/, $(SOURCES:.c=.o))

all: $(OBJS) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJECTFOLDER)/%.o: $(SOURCESFOLDER)/%.c $(HEADER)
	mkdir -p $(OBJECTFOLDER)
	$(CC) $(CFLAGS) -I$(SOURCESFOLDER) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: clean fclean all re
