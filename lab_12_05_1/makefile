CC := gcc
CFLAGS := -std=gnu99 -Wall -Werror -I inc/ -pedantic -g3
SRC_PATH := src/
UNIT_PATH := unit_tests/
SRC := $(SRC_PATH)io_file.c $(SRC_PATH)sort_array.c $(SRC_PATH)main.c $(UNIT_PATH)unit_test.c
UNIT :=  $(UNIT_PATH)unit_test.c
MAIN := $(SRC_PATH)main.c
INC := inc/
OUT := out/
OBJ := $(OUT)io_file.o $(OUT)sort_array.o
DLL := io_file.dll sort_array.dll
LIBSTART := $(CC) -shared
LIBEND := -Wl,--subsystem,windows -o

app.exe : $(DLL) $(OUT)main.o
	$(CC) -o app.exe  $(DLL) $(OUT)main.o

unit_tests.exe : $(DLL) $(OUT)unit_test.o
	$(CC) -o unit_tests.exe $(DLL) $(OUT)unit_test.o

%.dll : $(OUT)%.o
	$(LIBSTART) $< $(LIBEND) $@


$(OUT)%.o : $(SRC_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)%.o : $(UNIT_PATH)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY : clean
clean :
	rm $(OUT)*.o *.exe *.dll