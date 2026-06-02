NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
DFLAGS	= -MMD -MP
RM = rm -f

SRC =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp
		
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re