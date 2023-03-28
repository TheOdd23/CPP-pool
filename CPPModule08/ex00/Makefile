NAME			=	EasyFind
CC				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRCS			=	main.cpp
OBJS			=	$(SRCS:.cpp=.o)
RM				=	rm -f

.cpp.o		:
				$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
				echo Ready!

all			:	$(NAME)

clean		:	
				${RM} ${OBJS}

fclean		:	clean
				$(RM) $(NAME)
				echo All clean!

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .cpp.o $(NAME) $(OBJS) $(CC) $(CPPFLAGS)