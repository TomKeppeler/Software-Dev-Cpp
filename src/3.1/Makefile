NAME := hello
OPT := -Wall

all: $(NAME) $(NAME)C $(NAME)Nice

$(NAME).exe: $(NAME).cc
	clang++ $(OPT) $(NAME).cc -o $(NAME).exe

$(NAME)C.exe: $(NAME)C.cc
	clang++ $(OPT) $(NAME)C.cc -o $(NAME)C.exe

$(NAME)Nice.exe: $(NAME)Nice.cc
	clang++ $(OPT) $(NAME)Nice.cc -o $(NAME)Nice.exe

clean:
	rm $(NAME).exe
	rm $(NAME)C.exe
	rm $(NAME)Nice.exe
