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
	./Account

diff: $(NAME)
	clear
	rm -rf a
	./Account > a
	diff a 19920104_091532.log

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)
