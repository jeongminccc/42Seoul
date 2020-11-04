CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c 
OBJS = $(SRCS:.c=.o)

TARGET = do-op

all : $(TARGET)

%.o : %.c
		$(CC) $(CFLAGS) -c $<

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(TARGET)
		
re : fclean all
