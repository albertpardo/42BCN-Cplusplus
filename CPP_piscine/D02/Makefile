FLAGS = -Wall -Werror -Wextra -Wno-unused

.PHONY: all fclean

all:
	@bash ./menu.sh

poly:
	c++ ${FLAGS} 00_Sample_Class.cpp 00_main.cpp

canonical:
	c++ ${FLAGS} 02_Sample_Class.cpp 02_main.cpp

fclean:
	rm -f ./a.out
