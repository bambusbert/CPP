NAME = phonebook
CXX = c++
#CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
CXXFLAGS = -std=c++98 -g
RM = rm -f

SRC =	Account.cpp \
		tests.cpp
		
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re