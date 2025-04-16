# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 11:35:54 by apardo-m          #+#    #+#              #
#    Updated: 2024/07/19 11:37:22 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface

FLAGS = -Wall -Werror -Wextra -std=c++98
DPFLAGS	= -MMD -MP
CC = c++

SRCS =	AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \
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
