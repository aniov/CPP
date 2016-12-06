NAME = barcode

FLAGS = -Wall -Werror -Wextra

SRC =	BarCodeGenerator.cpp\
		ReadFromConsole.cpp\
		Create13NrCode.cpp\
		FileRead.cpp\
		CreateHTMLBarCode.cpp\
		TransformToBinary.cpp\
		

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
		@g++ -std=c++11 -o $(NAME) $(FLAGS) $(SRC)
clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME) $(NAME.exe)

re:	fclean all