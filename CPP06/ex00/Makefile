NAME      = convert
TEST_NAME = tester

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wpedantic
DFLAGS   = -MMD -MP
RM       = rm -f

SRC_COMMON =	ScalarConverter.cpp \
				get_type.cpp \
				format.cpp
SRC_MAIN   = main.cpp
SRC_TEST   = tester.cpp

OBJ_DIR = obj

OBJ_COMMON = $(SRC_COMMON:%.cpp=$(OBJ_DIR)/%.o)
OBJ_MAIN   = $(SRC_MAIN:%.cpp=$(OBJ_DIR)/%.o)
OBJ_TEST   = $(SRC_TEST:%.cpp=$(OBJ_DIR)/%.o)
DEP        = $(OBJ_COMMON:.o=.d) $(OBJ_MAIN:.o=.d) $(OBJ_TEST:.o=.d)

all: $(NAME)

$(NAME): $(OBJ_COMMON) $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): $(OBJ_COMMON) $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test