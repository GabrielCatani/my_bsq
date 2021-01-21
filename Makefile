CC = gcc
FLAGS = -Werror -Wall -Wextra
DBUG_FLAGS = -g3 -fsanitize=address

TARGET = my_bsq

SRCS_PATH = src/
OBJS_SRCS_PATH = srcs_obj/
OBJS_UTILS_PATH = utils_obj/
UTILS_PATH = utils/
INC = -I ./includes


SRCS := $(wildcard $(SRCS_PATH)*.c)
SRCS_NAMES := $(notdir $(SRCS))
UTILS := $(wildcard $(UTILS_PATH)*.c)
UTILS_NAMES := $(notdir $(UTILS))
SRCS_OBJS := $(addprefix $(OBJS_SRCS_PATH), $(SRCS_NAMES:.c=.o))
UTILS_OBJS := $(addprefix $(OBJS_UTILS_PATH), $(UTILS_NAMES:.c=.o))


all: $(TARGET)

$(TARGET): $(SRCS_OBJS) $(UTILS_OBJS)
	@$(CC) $(FLAGS) $(DBUG_FLAGS) $(INC) $(SRCS_OBJS) $(UTILS_OBJS) -o $@
	@echo "\033[32mLinking and generating \033[32;1m$(TARGET)\033[32;0m\033[32m binary."

$(OBJS_SRCS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p srcs_obj
	@$(CC) $(FLAGS) $(DBUG_FLAGS) $(INC) -c $< -o $@
	@echo "\033[32mGenerating \033[32;1m$@\033[32;0m\033[32m binary."

$(OBJS_UTILS_PATH)%.o:$(UTILS_PATH)%.c
	@mkdir -p utils_obj
	@$(CC) $(FLAGS) $(DBUG_FLAGS) $(INC) -c $< -o $@
	@echo "\033[32mGenerating \033[32;1m$@\033[32;0m\033[32m binary."

clean:
	@/bin/rm -rf $(OBJS_SRCS_PATH) $($(OBJS_UTILS_PATH))
	@echo "\033[32mRemoving all binaries..."

fclean: clean
	@/bin/rm -rf $(TARGET)
	@echo "\033[32mRemoving executable binary \033[32;1m$(TARGET)\033[32;0m\033[32m..."