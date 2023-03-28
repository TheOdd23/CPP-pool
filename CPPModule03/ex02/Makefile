NAME			=	TravailALaChaine
CC				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRCS			=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS			=	$(SRCS:.cpp=.o)
RM				=	rm -f

.cpp.o		:
				$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
				echo FragTrap is ready to highfive!

all			:	$(NAME)

clean		:	
				${RM} ${OBJS}

fclean		:	clean
				$(RM) $(NAME)
				echo Bye bye FragTrap

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .cpp.o $(NAME) $(OBJS) $(CC) $(CPPFLAGS)