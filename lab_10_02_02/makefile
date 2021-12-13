CC := gcc
CFLAGS := -std=c99 -Wall -Werror -I inc/ -pedantic -g3
SRC_PATH := src/
UNIT_PATH := unit_tests/
INC := inc/
OUT := out/
OBJ := $(OUT)io.o $(OUT)operations.o

app.exe : $(OBJ) $(OUT)main.o
	$(CC) -o app.exe  $(OBJ) $(OUT)main.o

unit_tests.exe : $(OBJ) $(OUT)unit_test.o
	$(CC) -o unit_tests.exe $(OBJ) $(OUT)unit_test.o

$(OUT)%.o : $(SRC_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)%.o : $(UNIT_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY : clean
clean :
	rm $(OUT)*.o *.exe
