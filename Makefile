NAME 		= so_long
LIBFT		= libft/libft.a

SRCS =	./parsing/set_map.c\
		./parsing/open_map.c\
		./parsing/all_map.c\
		./parsing/set_img.c\
		./parsing/gnl.c\
		./rendering/make_map.c\
		./rendering/key_press.c\
		main.c

OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MFLAGS	= -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
INCS	= -I libft
LFT		= -L libft -lft

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(MFLAGS) -o $(NAME) $(OBJS) $(LFT) $(INCS)

$(LIBFT) :
	@make -C libft/

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	@make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME)

re : fclean all

play : all clean