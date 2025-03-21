CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/libftprintf.a

LIBS = $(LIBFT) $(FT_PRINTF)

SRCS = parsing.c \
       push_swap.c \
       algorithme.c \
       moves/rx.c \
       moves/sx.c \
       moves/rrx.c \
       moves/px.c \
       free_list.c

OBJS = $(SRCS:.c=.o)

EXNAME = push_swap

all: $(EXNAME)

$(LIBFT):
	make bonus -C libft
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(EXNAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(EXNAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(EXNAME)

re: fclean all

.PHONY: all clean fclean re
