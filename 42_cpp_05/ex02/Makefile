# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 17:24:27 by htouil            #+#    #+#              #
#    Updated: 2024/05/06 14:10:55 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Exec

SRCS	= main.cpp Bureaucrat/Bureaucrat.cpp AForm/AForm.cpp \
		ShrubberyCreationForm/ShrubberyCreationForm.cpp RobotomyRequestForm/RobotomyRequestForm.cpp PresidentialPardonForm/PresidentialPardonForm.cpp \

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
