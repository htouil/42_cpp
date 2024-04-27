# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 16:41:29 by htouil            #+#    #+#              #
#    Updated: 2023/12/16 19:16:54 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= idea

SRCS	= main.cpp Animal/Animal.cpp Dog/Dog.cpp Cat/Cat.cpp WrongAnimal/WrongAnimal.cpp WrongCat/WrongCat.cpp Brain/Brain.cpp

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
