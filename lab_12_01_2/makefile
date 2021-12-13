CC := gcc
CFLAGS := -std=gnu99 -Wall -Werror -I inc/ -pedantic -g3
SRC_PATH := src/
UNIT_PATH := unit_tests/
UNIT :=  $(UNIT_PATH)unit_test.c
MAIN := $(SRC_PATH)main.c
INC := inc/
OUT := out/
OBJ := $(OUT)io.o $(OUT)array_operations.o
LIBSTART := $(CC) $(CFLAGS) -fPIC -shared -o
LIBEND := -Wl,--subsystem,windows -o


unit_tests.exe : $(OBJ) $(OUT)unit_test.o
	$(CC) -o unit_tests.exe $(OBJ) $(OUT)unit_test.o

array_operations.so : $(SRC_PATH)array_operations.c
	$(LIBSTART) array_operations.so  $(SRC_PATH)array_operations.c

io.so : $(SRC_PATH)io.c
	$(LIBSTART) io.so  $(SRC_PATH)io.c

$(OUT)%.o : $(SRC_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)%.o : $(UNIT_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY : clean
clean :
	rm $(OUT)*.o *.exe *.so