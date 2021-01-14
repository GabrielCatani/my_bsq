CC = gcc
FLAGS = -Werror -Wall -Wextra
DBUG_FLAGS = -g3 -fsanitize=address

TARGET = my_bsq
SRC := $(wildcard *.c)
BINS := $(SRC :%.c=%)


%: %.o
	@echo "Checking..."
	${CC} ${FLAGS} $< -o $@

%.o: %.c
	@echo "Creating object.."
	${CC} $(FLAGS) -c $<

TARGET: ${BINS}
	@echo "Generatin exe..."
	$(CC) $(FLAGS) $(DBUG_FLAGS) -o $(TARGET)

clean:
	/bin/rm -f $(BINS)

