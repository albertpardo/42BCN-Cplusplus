# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 12:47:56 by apardo-m          #+#    #+#              #
#    Updated: 2024/06/19 14:33:37 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myphomebook

FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = ${NAME}.cpp \
		Contact.cpp \
		PhoneBook.cpp 

HEADERS = Contact.hpp PhoneBook.hpp 

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n--> Final compiling ..."
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp Makefile $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "--> Remove Object files"
	rm -rf *.o

fclean: clean
	@echo "--> Remove files : $(NAME)"
	rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re
