NAME 		= so_long
LIBFT		= libft/libft.a

SRCS =	./parsing/set_map.c\
		./parsing/all_map.c\
		./parsing/set_img.c\
		./parsing/gnl.c\
		./playing/make_map.c\
		./playing/key_press.c\
		main.c

OBJS	=	$(SRCS:.c=.o)
CC		= gcc
# CFLAGS		= -Wall -Wextra -Werror
MFLAGS	=	-I. -Lmlx -lmlx -framework OpenGL -framework Appkit
INCS	=	-I includes -I libft
LFT		=	-L libft -lft -lncurses

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFT) $(INCS) $(MFLAGS)
	# $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFT) $(INCS)

$(LIBFT) :
	@make -C libft/

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS) $(MFLAGS)

clean :
	@make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME)

re : fclean all

play : all clean