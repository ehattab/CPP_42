# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 14:07:38 by ehattab           #+#    #+#              #
#    Updated: 2026/06/01 18:41:17 by ehattab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = .cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all