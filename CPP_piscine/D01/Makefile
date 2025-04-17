FLAGS = -Wall -Werror -Wextra -Wno-unused

.PHONY: all fclean

all:
	@bash ./menu.sh

newdelete:
	c++ ${FLAGS} 00_new_delete.cpp

newdelarr:
	c++ ${FLAGS} 01_new_delete_array.cpp

ref1: 
	c++ ${FLAGS} 02_ref1.cpp

ref2: 
	c++ ${FLAGS} 02_ref2.cpp

ref3: 
	c++ ${FLAGS} 02_ref3.cpp

stream1: 
	c++ ${FLAGS} 03_fstream1.cpp

fclean:
	rm -f ./a.out
	rm -f test.out
