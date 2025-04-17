FLAGS = -Wall -Werror -Wextra -Wno-unused

.PHONY: all fclean

all:
	@bash ./menu.sh

namespace:
	g++ ${FLAGS} 00_namespace.cpp

io:
	g++ ${FLAGS} 01_io.cpp

sample_2:
	g++ ${FLAGS} Sample.class02.cpp 02_main.cpp

sample_3:
	g++ ${FLAGS} Sample.class03.cpp 03_main.cpp

this_4:
	g++ ${FLAGS} Sample.class04.cpp 04_main.cpp

initlist_5:
	g++ ${FLAGS} Sample1.class05.cpp Sample2.class05.cpp 05_main.cpp

const_6:
	g++ ${FLAGS} Sample.class06.cpp 06_main.cpp

visi_7:
	g++ ${FLAGS} Sample.class07.cpp 07_main.cpp

class_8:
	g++ ${FLAGS} 08_main.cpp

accessors_9:
	g++ ${FLAGS} Sample.class09.cpp 09_main.cpp

comparisons_10:
	g++ ${FLAGS} Sample.class10.cpp 10_main.cpp

non_11:
	g++ ${FLAGS} Sample.class11.cpp 11_main.cpp

point_12:
	g++ ${FLAGS} Sample.class12.cpp 12_main.cpp

fclean:
	rm -f ./a.out
