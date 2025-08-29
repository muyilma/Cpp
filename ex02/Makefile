NAME=Account

CXX = c++
CXXFLAGS =-std=c++98 -g
SRC = Account.cpp tests.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	clear
	./phonebook

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)
