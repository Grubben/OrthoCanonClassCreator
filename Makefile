# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amc <amc@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 15:14:17 by akliek            #+#    #+#              #
#    Updated: 2023/05/30 14:53:10 by amc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = orthodox

CC		= clang++

CFLAGS = -Wall -Werror -Wextra

SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)


$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	
		make clean
		make all

all: $(NAME)
