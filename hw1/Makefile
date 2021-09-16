CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: MyString.cpp MyString.hpp testMyString.cpp
	echo ----------compiling testMystring.cpp to a executable testMyString--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) MyString.cpp testMyString.cpp   -o  testMyString
	
clean:
	echo -----------------removing executable program-----------------
	rm testMyString
