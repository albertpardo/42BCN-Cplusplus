# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 15:09:04 by apardo-m          #+#    #+#              #
#    Updated: 2024/10/04 16:47:24 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = whatever

FLAGS = -Wall -Werror -Wextra -std=c++98 # -g3
DPFLAGS	= -MMD -MP
CC = c++

SRCS =	main.cpp

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
