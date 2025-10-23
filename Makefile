# ------------------------
# Projet Dungeon Master
# ------------------------

NAME        = dungeon_master

# --- Sources (tous les .cpp + glad.c) ---
SRC         = $(wildcard src/*.cpp) src/glad.c
OBJS        = $(SRC:.cpp=.o)
OBJS        := $(OBJS:.c=.o)  # convert glad.c -> glad.o

# --- Includes ---
INCLUDE     = -I./include -I$(HOME)/.froot/include

# --- Compilateur ---
CC          = g++
CXXFLAGS    = -std=c++23 -Wall -Wextra -W -g

# --- Librairies ---
SFML_LIBS   = -L$(HOME)/.froot/lib/ -llapin -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lX11
OPENGL_LIBS = -lGL -lGLU -ldl -lpthread
GLFW_LIBS   = -lglfw
OPENCV_LIBS = -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_video -lopencv_videoio -lopencv_core
OTHER_LIBS  = -lstdc++ -lm -lavcall -lusb -ludev

# --- LDFLAGS ---
LDFLAGS     = $(SFML_LIBS) $(OPENGL_LIBS) $(GLFW_LIBS) $(OPENCV_LIBS) $(OTHER_LIBS)

# ------------------------
# Règles
# ------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

# Compilation des .cpp et .c
%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

%.o: %.c
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# Exécuter
run: all
	./$(NAME)

# Debug
g: all
	gdb --args ./$(NAME)

# Nettoyage
clean:
	find . -name "*.o" -delete
	find . -name "*~" -delete

fclean: clean
	rm -f $(NAME) $(NAME).a

re: fclean all

# Arbre du projet
tree: fclean
	tree
