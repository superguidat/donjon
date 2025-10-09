NAME =			donjon_master

SRC =			$(wildcard ./src/*.cpp)

OBJS =			$(SRC:.cpp=.o)

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
clean:
			rm -f  *~ *.o
fclean: clean
			rm -f $(NAME)
re: fclean all

tree: fclean
			tree
