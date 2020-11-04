CC = gcc

INC = includes
CFLAGS = -Wall -Wextra -Werror -c

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

TARGET = libft.a

all : $(TARGET)

%.o : %.c
		$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(TARGET) : $(OBJS)
		ar -rc $@ $(OBJS)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(TARGET)
		
re : fclean all
