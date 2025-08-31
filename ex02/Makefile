NAME =		a.out

OBJ_DIR =	obj/

INC = \
			AForm.hpp \
			Bureaucrat.hpp \
			PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp \
			ShrubberyCreationForm.hpp

SRC = \
			AForm.cpp \
			Bureaucrat.cpp \
			main.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp

OBJ =		$(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: %.cpp $(INC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --leak-check=full \
	--show-leak-kinds=definite,indirect,possible \
	--track-fds=yes ./$(NAME)

.PHONY: all clean fclean re val
