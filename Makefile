NAME = libft.a

SRC = ft_isalpha.c 
OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 
$(OBJS): $(SRC)
	gcc -Wall -Werror -Wextra -c $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all