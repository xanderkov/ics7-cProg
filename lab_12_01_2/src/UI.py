from tkinter import *
import ctypes
io = ctypes.CDLL('./io.so')
opre = ctypes.CDLL('./array_operations.so')

io.read_line.argtypes = (ctypes.POINTER(ctypes.c_char), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
io.read_array.argtypes = (ctypes.POINTER(ctypes.c_char), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
opre.get_count_of_squares.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)

def move_array():
    str = array_ent.get()
    n = n_ent.get()
    if (len(n) > 0):
        n = int(n)
    else:
        n = io.get_count(str.encode('utf-8'))
    arr = (ctypes.c_int * n)()
    io.read_array(str.encode('utf-8'), arr, n)
    k = k_ent.get()
    if (len(k) > 0):
        opre.move_array(arr, n, int(k))
    myText.set(list(arr))

def place_array():
    str = array_ent.get()
    n = n_ent.get()
    if (len(n) > 0):
        n = int(n)
    else:
        n = io.get_count(str.encode('utf-8'))
    arr = (ctypes.c_int * n)()
    io.read_array(str.encode('utf-8'), arr, n)
    new_n = 0
    new_n = opre.get_count_of_squares(arr, n)
    new_arr = (ctypes.c_int * new_n)()
    opre.place_in_array_squares(arr, n, new_arr, new_n)
    myText.set(list(new_arr))

def clear_all():
    array_ent.delete(0, 'end')
    n_ent.delete(0, 'end')
    k_ent.delete(0, 'end')


master = Tk()
master.configure()
myText = StringVar()

array_ent = Entry(master, width=40)
n_ent = Entry(master, width=7)
Label(master, text="Массив").grid(row=2, column=0)
array_ent.grid(row=3, column=0)
Label(master, text="Кол-во эл-ов").grid(row=2, column=1)
n_ent.grid(row=3, column=1)

k_ent = Entry(master, width=7)
Label(master, text="K").grid(row=5, column=1)
k_ent.grid(row=7, column=1)

Label(master, text="--------------------").grid(row=5, column=0)

get_move = Button(master, text="Сдвинуть цикл. массив на k позиций влево", command=move_array)
get_move.grid(row=7, column=0)
Label(master, text="--------------------").grid(row=8, column=0)
get_place = Button(master, text="Переместить из массива полные квадраты", command=place_array)
get_place.grid(row=9, column=0)
Label(master, text="--------------------").grid(row=10, column=0)
Button(master, text="Очистить", command=clear_all).grid(row=11, column=1)
result = Label(master, text="REsult", textvariable=myText, background="white", width=30).grid(row=11, column=0)

mainloop()
