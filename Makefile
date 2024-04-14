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
	cc $(OBJS) $(LIBFT) -o $(PUSH_SWAP)

$(BUILD_DIR)/%o : %c $(LIBFT)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd $(LIBFT_DIR) && make && cd ..

clean:
	rm -rf $(BUILD_DIR)/$(SRC_FOLDER)
	cd $(LIBFT_DIR) && make clean && cd ..

fclean: clean
	rm -f $(PUSH_SWAP)
	cd $(LIBFT_DIR) && make fclean && cd ..


re : fclean $(PUSH_SWAP)
	cd $(LIBFT_DIR) && make re && cd ..

.PHONY:  all clean fclean re
