# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 15:36:59 by apardo-m          #+#    #+#              #
#    Updated: 2024/06/25 17:59:50 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphism

FLAGS = -Wall -Werror -Wextra -std=c++98
DPFLAGS	= -MMD -MP
CC = c++

SRCS =	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp

DIR_OBJ	= .obj/
OBJS = $(SRCS:%.cpp=$(DIR_OBJ)%.o)
DEP	 = $(OBJS:%.o=%.d)

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "\n--> Final compiling ..."
	$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJ)%.o: %.cpp Makefile 
	$(CC) $(FLAGS) $(DPFLAGS) -c $< -o $@

clean:
	@echo "--> Remove Object files"
	rm -rf $(DIR_OBJ)

fclean: clean
	@echo "--> Remove files : $(NAME)"
	rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re

-include $(DEP)
