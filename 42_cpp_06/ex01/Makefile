# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 18:49:33 by htouil            #+#    #+#              #
#    Updated: 2024/05/20 21:44:00 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Serialize

SRCS	= main.cpp Serializer/Serializer.cpp

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
