NAME			=	BureaucratiePt3
CC				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRCS			=	main.cpp AForm.cpp Bureaucrat.cpp ShruberryCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp
OBJS			=	$(SRCS:.cpp=.o)
FILES			=	*_shruberry
RM				=	rm -f

.cpp.o		:
				$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
				echo Ready to get bored yet another time

all			:	$(NAME)

clean		:	
				$(RM) $(OBJS) $(FILES)

fclean		:	clean
				$(RM) $(NAME) $(FILES)
				echo Shift"'"s over, thank god!

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .cpp.o $(NAME) $(OBJS) $(CC) $(CPPFLAGS)