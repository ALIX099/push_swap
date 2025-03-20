CC = cc

CFLAGS = -Wextra -Wall -Werror -g3

LIBS = libft/libft.a \
	ft_printf/libftprintf.a

SRCS = parsing.c \
	push_swap.c \
	algorithme.c \
	moves/rx.c \
	moves/sx.c \
	moves/rrx.c \
	moves/px.c \

OBJS = $(SRCS:.c=.o)

EXNAME = push_swap

all: libft ft_printf $(EXNAME)

libft:
	make bonus -C libft
	make -C libft

ft_printf:
	make -C ft_printf

$(EXNAME): $(LIBS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(EXNAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(EXNAME)

re: fclean all

.PHONY: all libft ft_printf clean fclean re
