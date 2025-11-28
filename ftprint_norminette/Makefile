NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CONV = ft_conversions.c
SRC_UTIL = ft_utils.c
SRC_NUM = ft_numbers.c
SRC_MAIN = ft_printf.c

SRC_FILES = $(SRC_MAIN) $(SRC_CONV) $(SRC_NUM) $(SRC_UTIL)
OBJ_FILES = $(SRC_FILES:.c=.o)

TEST_SRC = test_main.c
TEST_NAME = test_ft_printf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lftprintf -o $(TEST_NAME)

.PHONY: all clean fclean re test