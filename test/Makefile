#names
OUT = TEST
NAME = lib$(OUT).a

#other
LAPINLINKS=
LIB=-lgtest_main -lgtest -lpthread -l$(OUT) # -lgcov
INCLUDE=-I../include/
SRC =$(wildcard ./*.cpp) $(wildcard ./*/*.cpp) 
OBJ =$(SRC:.cpp=.o)
CPP = b++

#flags
CPPFLAGS= -std=c++23

DFLAGS = -O0 -g -g3

GCOVFLAGS = #--coverage

CXXFLAGS = -W -Wall -Werror -rdynamic

FLAGS = $(CPPFLAGS) $(CXXFLAGS) $(GCOVFLAGS) $(DFLAGS) #$(LAPINLINKS)
all: $(OUT)

$(OUT): $(OBJ)
ifeq ($(LIBLAPIN), 1)
	$(CPP) $(OBJ) $(INCLUDE) $(FLAGS) $(LAPINLINKS) -o $(OUT)
else
	$(CPP) $(OBJ) $(INCLUDE) $(FLAGS) -o $(OUT)
endif

lib: $(LIBSTAOUT)

$(LIBSTAOUT): $(OBJ)
	ar cr $(LIBSTAOUT) $(OBJ)

test:
	cd test/ && $(MAKE)

clean:
	@rm -f $(OBJ)
	@rm -f $(shell find ./ -name "*~")
	@rm -f $(shell find ./ -name "*.gcno")
	@rm -f $(shell find ./ -name "*.gcov")
	@rm -f vgcore*
	@rm -f man_coverage.info
	@rm -f -r report

fclean: clean
	@rm -f $(OUT)
	@rm -f test/test$(OUT)

re: fclean all

resta:fclean lib

.PHONY: clean fclean

.cpp.o:
	b++ -c $< $(INCLUDE) -o $@ -fPIC $(FLAGS)

report:$(NAME)
	./$(NAME)
	lcov --capture --directory . --output-file main_coverage.info
	genhtml main_coverage.info --output-directory report
	firefox report/index.html
