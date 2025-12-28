# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malebrun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 21:24:53 by malebrun          #+#    #+#              #
#    Updated: 2025/12/28 20:38:55 by malebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUSNAME = checker
HEADER = sources/push_swap.h
BONUSHEADER = bonus_source/bonus_checker.h
BONUSFOLDER = bonus_source
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
BONUSSOURCES = bonus_actionnode.c \
			bonus_node.c \
			bonus_rotate.c \
			bonus_atol.c \
			bonus_exec_action.c \
			bonus_parser.c \
			bonus_rrotate.c \
			bonus_checker.c \
			bonus_is.c \
			bonus_push.c \
			bonus_swap.c

SRCS = $(addprefix $(SOURCESFOLDER)/, $(SOURCES))
OBJS = $(addprefix $(OBJECTFOLDER)/, $(SOURCES:.c=.o))
BONUS = $(addprefix $(BONUSFOLDER)/, $(BONUSSOURCES))
BONUSOBJS = $(addprefix $(OBJECTFOLDER)/, $(BONUSSOURCES:.c=.o))

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJECTFOLDER)/%.o: $(SOURCESFOLDER)/%.c $(HEADER)
	mkdir -p $(OBJECTFOLDER)
	$(CC) $(CFLAGS) -I$(SOURCESFOLDER) -c $< -o $@

$(OBJECTFOLDER)/bonus_%.o: $(BONUSFOLDER)/bonus_%.c $(BONUSHEADER)
	mkdir -p $(OBJECTFOLDER)
	$(CC) $(CFLAGS) -I$(BONUSFOLDER) -c $< -o $@

$(BONUSNAME): $(BONUSOBJS)
	$(CC) $(CFLAGS) $(BONUSOBJS) -o $(BONUSNAME)

bonus : $(BONUSNAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUSNAME)

clean:
	rm -f $(OBJS) $(BONUSOBJS)
	rm -rf $(OBJECTFOLDER)

re: fclean all

.PHONY: clean fclean all re
