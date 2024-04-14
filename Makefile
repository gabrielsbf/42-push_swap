NAME=push_swap

EXEC_DIR = ./

PUSH_SWAP = $(EXEC_DIR)$(NAME)

CC=cc

INCLUDE_FOLDER = ./includes

CFLAGS=-Wall -Wextra -Werror -I $(INCLUDE_FOLDER)

SRC_FOLDER = ./srcs

BUILD_DIR = ./build

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

RAW_SRCS = $(shell find $(SRC_FOLDER))

SRCS = $(filter %.c, $(RAW_SRCS))

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(PUSH_SWAP)

$(PUSH_SWAP) : $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(PUSH_SWAP)

$(BUILD_DIR)/%.o : %.c $(LIBFT)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd $(LIBFT_DIR) && make && cd ..

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(LIBFT_DIR)/build/srcs

fclean: clean
	rm -f $(PUSH_SWAP)
	rm -f $(LIBFT)

re : fclean $(LIBFT) $(PUSH_SWAP)

.PHONY:  all clean fclean re
