NAME =			murasaki

SRC =			$(wildcard ./*.cpp)

OBJS =			$(SRC:.cpp=.o)

INCLUDE =		-I./../include

CC =			g++

FLAGS =			-W -Wall -Wextra -Wno-write-strings -g

LDFLAGS =		-L./ -lpolimorphism_parametric -L$(GTEST_DIR)/lib -lgtest -lgtest_main -lgcov

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
