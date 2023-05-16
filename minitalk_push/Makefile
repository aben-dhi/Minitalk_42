NAME_CLIENT	=	client
NAME_SERVER	=	server
NAME_CLIENT_BN	=	client_bonus
NAME_SERVER_BN	=	server_bonus

SRCS_CLIENT	=	ft_client.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_itoa.c
SRCS_SERVER	=	ft_server.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_itoa.c
SRCS_CLIENT_BN	=	ft_client_bonus.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_itoa.c
SRCS_SERVER_BN	=	ft_server_bonus.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_itoa.c 

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT_BN	=	$(SRCS_CLIENT_BN:.c=.o)
OBJS_SERVER_BN	=	$(SRCS_SERVER_BN:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all:		$(NAME_CLIENT) $(NAME_SERVER)

bonus:		$(NAME_CLIENT_BN) $(NAME_SERVER_BN)

$(NAME_CLIENT):	$(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER)
		$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT_BN):	$(OBJS_CLIENT_BN)
		$(CC) $(CFLAGS) $(OBJS_CLIENT_BN) -o $(NAME_CLIENT_BN)

$(NAME_SERVER_BN):	$(OBJS_SERVER_BN)
		$(CC) $(CFLAGS) $(OBJS_SERVER_BN) -o $(NAME_SERVER_BN)

clean:
		$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BN) $(OBJS_SERVER_BN)

fclean:		clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BN) $(NAME_SERVER_BN)

re:			fclean all

.PHONY:		all clean fclean re
