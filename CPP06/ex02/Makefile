NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wpedantic
DFLAGS	= -MMD -MP
RM = rm -f

SRC =	Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp \
		main.cpp

OBJ_DIR = obj

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(SRC:%.cpp=$(OBJ_DIR)/%.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re