NAME		=	No,youneedform28B,not28C...

SRCS		= 	main.cpp Bureaucrat.cpp AForm.cpp \ 
			  	ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \ 
			  	PresidentialPardonForm.cpp

OBJDIR  	=	obj
OBJS     	=  $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "Compiling \nDone\n"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re