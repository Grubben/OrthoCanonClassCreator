# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 15:14:17 by akliek            #+#    #+#              #
#    Updated: 2023/03/21 09:33:07 by amaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bin/orthodox

CXXFLAGS = -Wall -Werror -Wextra

SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)


$(NAME)	: $(OBJS)
		# mkdir bin
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

c		:
			$(RM) $(NAME)

f		: c
			$(RM) $(OBJS)

r		: f $(NAME)
