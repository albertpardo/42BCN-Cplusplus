FLAGS = -Wall -Werror -Wextra 

.PHONY: all fclean

all:
	@bash ./menu.sh

cast2:
	cc ${FLAGS} c_cast_2.c

cast3:
	cc ${FLAGS} -Wno-unused c_cast_3.c

updown:
	c++ ${FLAGS} -Wno-unused updowncast.cpp

values:
	c++ ${FLAGS} -Wno-unused static_cast_values.cpp

staticupdown:
	c++ ${FLAGS} -Wno-unused static_cast_updowncast.cpp 

dynamic:
	c++ $(FLAGS) -Wno-unused dynamic_cast.cpp

reinterpret:
	c++ $(FLAGS) -Wno-unused reinterpret_cast.cpp

constant:
	c++ $(FLAGS) -Wno-unused constant_cast.cpp

castoper:
	c++ $(FLAGS) -Wno-unused cast_operators.cpp

explicit:
	c++ $(FLAGS) -Wno-unused explicit.cpp


fclean:
	rm -f ./a.out
