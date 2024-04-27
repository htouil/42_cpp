# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 22:07:42 by htouil            #+#    #+#              #
#    Updated: 2024/03/18 21:47:14 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= sound

SRCS	= main.cpp Animal/Animal.cpp Dog/Dog.cpp Cat/Cat.cpp WrongAnimal/WrongAnimal.cpp WrongCat/WrongCat.cpp

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
