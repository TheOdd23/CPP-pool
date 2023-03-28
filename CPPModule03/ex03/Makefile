NAME			=	OkCaDevientBizarre
CC				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRCS			=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS			=	$(SRCS:.cpp=.o)
RM				=	rm -f

.cpp.o		:
				$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
				echo DiamondTrap is ready for its exitential crisis!

all			:	$(NAME)

clean		:	
				${RM} ${OBJS}

fclean		:	clean
				$(RM) $(NAME)
				echo Bye bye DiamondTrap

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .cpp.o $(NAME) $(OBJS) $(CC) $(CPPFLAGS)