CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -g3
SRC_PATH := src/
UNIT_PATH := unit_tests/
SRC := $(SRC_PATH)io_file.c $(SRC_PATH)sort_array.c $(SRC_PATH)main.c $(UNIT_PATH)unit_test.c
UNIT :=  $(UNIT_PATH)unit_test.c
MAIN := $(SRC_PATH)main.c
INC := inc/
OUT := out/
OBJ := $(OUT)io_file.o $(OUT)sort_array.o

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
	rm *.o *.exe