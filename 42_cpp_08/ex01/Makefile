# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 19:36:56 by htouil            #+#    #+#              #
#    Updated: 2024/06/12 19:39:41 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 

SRCS	= main.cpp Span/Span.cpp

OBJS	= ${SRCS:.cpp=.o}

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
