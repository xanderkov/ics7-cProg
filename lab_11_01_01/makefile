CC := gcc
CFLAGS := -std=gnu99 -Wall -Werror -I inc/ -pedantic -g3
SRC_PATH := src/
INC := inc/
OUT := out/
UNIT_PATH := unit_tests/
OBJ := $(OUT)operations.o $(OUT)my_snprintf.o


unit_tests.exe : $(OBJ) $(OUT)unit_test.o
	$(CC) -o unit_tests.exe $(OBJ) $(OUT)unit_test.o


app.exe : $(OBJ)
	$(CC) -o app.exe $(OBJ)

$(OUT)%.o : $(SRC_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)%.o : $(UNIT_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY : clean
clean :
	rm $(OUT)*.o *.exe