NAME = PmergeMe

CXX = c++
CXXFLAGS =-std=c++98 -Wall -Wextra -Werror -g
SRC = main.cpp PmergeMe.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	make clean
	clear
	./$(NAME) 5 4 2 6 3 1 33234 3412 3 21

leak:
	valgrind ./$(NAME) 5 4 2 6 3 1 33234 3412 3 21

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all 