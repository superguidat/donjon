<<<<<<< HEAD
NAME =			donjon_master

SRC =			$(wildcard ./src/*.cpp)
=======
OUT =libDungeon.a

INCLUDE=-I./include/
SRC =$(shell find src/ -name "*.c")
OBJ =$(SRC:.c=.o)
CC = gcc
>>>>>>> 9325605 (changement Incroyable!)

#flags "-g pour debug"
CFLAGS = $(INCLUDE) -Wall -Wextra -std=gnu11

<<<<<<< HEAD
INCLUDE =		-I././include -I$(HOME)/.froot/include/

CC =			b++

FLAGS=			-W -Wall -Wextra -g #-O3 -ffast-math -march=native # -g # -Wno-write-strings 

LDFLAGS =		-L./ -L$(GTEST_DIR)/lib -g

LDFLAGS +=		$(LAPINFLAGS)

all: 			$(NAME)

test: 			all
			./$(NAME)

$(NAME):$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
.cpp.o:
			$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
ar:$(OBJS)
			ar rc $(NAME).a $(OBJS)
g:
			gdb --arg ./$(NAME)
=======
all: $(OUT)

$(OUT): $(OBJ)
	ar crs $(OUT) $(OBJ)

>>>>>>> 9325605 (changement Incroyable!)
clean:
	@rm -f $(OBJ)
	@rm -f $(shell find ./ -name "*~")

fclean: clean
	@rm -f $(OUT)

re: fclean all
