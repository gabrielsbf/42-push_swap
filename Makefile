NAME=push_swap

EXEC_DIR = ./

PUSH_SWAP = $(EXEC_DIR)/$(NAME)

CC=cc

INCLUDE_FOLDER = ./includes

CFLAGS=-Wall -Wextra -Werror -I $(INCLUDE_FOLDER)

SRC_FOLDER = ./srcs

BUILD_DIR = ./build

RAW_SRCS = $(shell find $(SRC_FOLDER))

SRCS = $(filter %.c, $(RAW_SRCS))

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(PUSH_SWAP)

$(PUSH_SWAP) : $(OBJS)
	cc $(OBJS) -o $(PUSH_SWAP)

BUILD_DIR/%o : %c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/$(SRC_FOLDER)

fclean: clean
	rm -f $(PUSH_SWAP)

re : fclean $(PUSH_SWAP)

.PHONY:  all clean fclean re
