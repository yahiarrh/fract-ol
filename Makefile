NAME = fractol

SRC	=	fractol.c

CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm  -rf

HEADERM =  fractol.h

OBJS	= $(SRC:.c=.o)


%.o: %.c $(HEADERM)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

clean :
	$(RM) $(OBJS)


fclean : clean
	$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re