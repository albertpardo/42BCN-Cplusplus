# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 16:06:30 by apardo-m          #+#    #+#              #
#    Updated: 2024/06/25 17:23:31 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = noviolence 

FLAGS = -Wall -Werror -Wextra -std=c++98
DPFLAGS	= -MMD -MP
CC = c++

SRCS = 	HumanA.cpp \
		HumanB.cpp \
		main.cpp \
		Weapon.cpp

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
	$(CC) $(CFLAGS) $(DPFLAGS) -c $< -o $@

clean:
	@echo "--> Remove Object files"
	rm -rf $(DIR_OBJ)

fclean: clean
	@echo "--> Remove files : $(NAME)"
	rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re

-include $(DEP)
