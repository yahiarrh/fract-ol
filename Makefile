NAME = fractol

SRC	=	fractal.c fractol.c ft_printf.c draw.c  utils.c keys.c mouse.c

CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm  -rf

HEADERM =  fractol.h

OBJS	= $(SRC:.c=.o)

%.o: %.c $(HEADERM)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -Ofast -o $(NAME) 

clean :
	$(RM) $(OBJS)


fclean : clean
	$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re