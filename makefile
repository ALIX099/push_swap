CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = includes/libft/libft.a
FT_PRINTF = includes/ft_printf/libftprintf.a

LIBS = $(LIBFT) $(FT_PRINTF)

DIR_B = bonus
DIR_M = mandatory

EXNAME = push_swap
NAMEB = checker

SRCS_M = $(DIR_M)/parsing.c \
         $(DIR_M)/push_swap.c \
         $(DIR_M)/moves/rx.c \
         $(DIR_M)/moves/sx.c \
         $(DIR_M)/moves/rrx.c \
         $(DIR_M)/moves/px.c \
         $(DIR_M)/algo_area/is_sorted.c \
         $(DIR_M)/algo_area/minimum.c \
         $(DIR_M)/algo_area/bubble_sort.c \
         $(DIR_M)/algo_area/first_algorithme.c \
         $(DIR_M)/algo_area/sec_algorithme.c \
         $(DIR_M)/algo_area/append_to_array.c \
         $(DIR_M)/algo_area/should_do.c \
         $(DIR_M)/algo_area/maximum.c

OBJS_M = $(SRCS_M:.c=.o)

SRCS_B = $(DIR_B)/get_next_line_bonus/get_next_line_bonus.c \
         $(DIR_B)/get_next_line_bonus/get_next_line_utils_bonus.c \
         $(DIR_B)/checker_bonus.c \
         $(DIR_B)/checker_helper_bonus.c \
         $(DIR_B)/moves/px_bonus.c \
         $(DIR_B)/moves/rx_bonus.c \
         $(DIR_B)/moves/rrx_bonus.c \
         $(DIR_B)/moves/sx_bonus.c \
         $(DIR_M)/algo_area/is_sorted.c \
         $(DIR_M)/parsing.c \
         $(DIR_M)/algo_area/minimum.c


OBJS_B = $(SRCS_B:.c=.o)

all: $(EXNAME)

bonus: $(NAMEB)

$(LIBFT):
	make bonus -C includes/libft
	make -C includes/libft

$(FT_PRINTF):
	make -C includes/ft_printf

$(EXNAME): $(OBJS_M) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS_M) $(LIBS) -o $(EXNAME)

$(NAMEB): $(OBJS_B) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS_B) $(LIBS) -o $(NAMEB)

clean:
	make clean -C includes/libft
	make clean -C includes/ft_printf
	rm -rf $(OBJS_M) $(OBJS_B)

fclean: clean
	make fclean -C includes/libft
	make fclean -C includes/ft_printf
	rm -rf $(EXNAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus