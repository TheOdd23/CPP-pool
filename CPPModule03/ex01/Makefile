NAME			=	SerenaMonAmour
CC				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRCS			=	main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS			=	$(SRCS:.cpp=.o)
RM				=	rm -f

.cpp.o		:
				$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
				echo ScavTrap is Ready to guard the gates!

all			:	$(NAME)

clean		:	
				${RM} ${OBJS}

fclean		:	clean
				$(RM) $(NAME)
				echo Bye bye ScavTrap

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .cpp.o $(NAME) $(OBJS) $(CC) $(CPPFLAGS)