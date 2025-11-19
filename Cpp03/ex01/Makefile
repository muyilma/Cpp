NAME=ClapTrap

CXX = c++
CXXFLAGS =-Wall -Wextra -Werror -std=c++98  
SRC = main.cpp ClapTrap.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	make clean
	clear
	./$(NAME)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all