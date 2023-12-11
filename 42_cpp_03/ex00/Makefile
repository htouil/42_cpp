# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 14:49:00 by htouil            #+#    #+#              #
#    Updated: 2023/12/09 16:37:44 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= claptrap

SRCS	= main.cpp ClapTrap.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPC	= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

.PHONY	= all clean fclean re

all: $(NAME)

%.o: %.cpp
	$(CPPC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPPC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
