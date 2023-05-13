NAME_CLIENT	=	client
NAME_SERVER	=	server

SRCS_CLIENT	=	ft_client.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_itoa.c
SRCS_SERVER	=	ft_server.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_itoa.c

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER)
		$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

clean:
		$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:		clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:			fclean all

.PHONY:		all clean fclean re
