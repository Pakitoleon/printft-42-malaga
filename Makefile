NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_mayus \
		ft_minus \
		ft_num_entero \
		ft_printf \
		ft_punt_hexa \
		ft_putchar \
		ft_putnbr \
		ft_putstr \
		ft_strlen \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
#OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
#OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix _bonus.o, $(FILES_BONUS)))

OBJ = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re


