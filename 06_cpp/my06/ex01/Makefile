# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 17:23:43 by apardo-m          #+#    #+#              #
#    Updated: 2024/09/09 16:49:16 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

FLAGS = -Wall -Werror -Wextra -std=c++98
DPFLAGS	= -MMD -MP
CC = c++

SRCS =	Serializer.cpp \
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
