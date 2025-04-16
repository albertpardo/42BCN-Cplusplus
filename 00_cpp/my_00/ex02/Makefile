# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 14:01:23 by apardo-m          #+#    #+#              #
#    Updated: 2024/06/19 14:34:21 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = 	Account.cpp tests.cpp 

HEADER = Account.hpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n--> Final compiling ..."
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "--> Remove Object files"
	rm -rf *.o

fclean: clean
	@echo "--> Remove files : $(NAME)"
	rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re
