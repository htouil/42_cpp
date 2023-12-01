# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 22:27:52 by htouil            #+#    #+#              #
#    Updated: 2023/11/29 17:52:16 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie

SRCS	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPC	= g++

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
