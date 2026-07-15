NAME = PmergeMe

CXX = c++
CXXFLAGS =-std=c++98 -Wall -Wextra -Werror
SRC = main.cpp PmergeMe.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	make clean
	clear
	./$(NAME) "1 * 2 3 *"

leak:
	valgrind ./$(NAME) 

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all 