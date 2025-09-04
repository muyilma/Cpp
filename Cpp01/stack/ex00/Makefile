NAME=Zombie

CXX = c++
CXXFLAGS =-std=c++98 -g #-Wall -Wextra -Werror 
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	clear
	./$(NAME)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all