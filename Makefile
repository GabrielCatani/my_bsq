CC = gcc
FLAGS = -Werror -Wall -Wextra
DBUG_FLAGS = -g3 -fsanitize=address

TARGET = my_bsq

SRCS_PATH = src/
OBJS_PATH = obj/
INC = -I ./includes


SRCS := $(wildcard $(SRCS_PATH)*.c)
SRCS_NAMES := $(notdir $(SRCS))
OBJS := $(addprefix $(OBJS_PATH), $(SRCS_NAMES:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(FLAGS) $(DBUG_FLAGS) $(INC) $(OBJS) -o $@
	@echo "\033[32mLinking and generating \033[32;1m$(TARGET)\033[32;0m\033[32m binary."

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) $(DBUG_FLAGS) $(INC) -c $< -o $@
	@echo "\033[32mGenerating \033[32;1m$@\033[32;0m\033[32m binary."

clean:
	@/bin/rm -rf $(OBJS_PATH)
	@echo "\033[32mRemoving all binaries..."

fclean: clean
	@/bin/rm -rf $(TARGET)
	@echo "\033[32mRemoving executable binary \033[32;1m$(TARGET)\033[32;0m\033[32m..."