from Tkinter import *
import shared_funcs as sf

#First thing is to create an instance of a Tkinter class
top = Tk()
#Title Bar text.
top.title("Calculator")
#The StringVar equation is what is shown and edited in the Entry field
equation = StringVar()
equation.set("0")
#Create the grid for the GUI so it can be resized.
Grid.rowconfigure(top, 0, weight=1)
Grid.columnconfigure(top, 0, weight=1)
#Create a frame of the GUI so we can resize it.
frame=Frame(top)
frame.grid(row=0, column=0, sticky=N+S+E+W)
#This is the text field at the top of the calculator.
Entry(frame, exportselection=0, textvariable=equation).grid(
    row=0,column=0, columnspan=6, pady=3, sticky=N+S+E+W)
#The following commands are the Buttons on the calculator.
Button(frame, text="C", command=sf.clear).grid(row=1, column=0,
        sticky=N+S+E+W)
Button(frame, text="/", command=lambda: sf.press("/")).grid(
        row=1, column=1, sticky=N+S+E+W)
Button(frame, text="*", command=lambda: sf.press("*")).grid(
        row=1, column=2, sticky=N+S+E+W)
Button(frame, text="-", command=lambda: sf.press("-")).grid(
        row=1, column=3, sticky=N+S+E+W)
Button(frame, text="7", command=lambda: sf.press(7)).grid(
        row=2, column=0, sticky=N+S+E+W)
Button(frame, text="8", command=lambda: sf.press(8)).grid(
        row=2, column=1, sticky=N+S+E+W)
Button(frame, text="9", command=lambda: sf.press(9)).grid(
        row=2, column=2, sticky=N+S+E+W)
Button(frame, text="6", command=lambda: sf.press(6)).grid(
        row=3, column=2, sticky=N+S+E+W)
Button(frame, text="5", command=lambda: sf.press(5)).grid(
        row=3, column=1, sticky=N+S+E+W)
Button(frame, text="4", command=lambda: sf.press(4)).grid(
        row=3, column=0, sticky=N+S+E+W)
Button(frame, text="3", command=lambda: sf.press(3)).grid(
        row=4, column=2, sticky=N+S+E+W)
Button(frame, text="2", command=lambda: sf.press(2)).grid(
        row=4, column=1, sticky=N+S+E+W)
Button(frame, text="1", command=lambda: sf.press(1)).grid(
        row=4, column=0, sticky=N+S+E+W)
Button(frame, text="x^2", command=lambda: sf.press("**")).grid(
        row=5, column=0, sticky=N+S+E+W)
Button(frame, text="0", command=lambda: sf.press(0)).grid(
        row=5, column=1, sticky=N+S+E+W)
Button(frame, text="+", command=lambda: sf.press("+")).grid(
        row=2, column=3, sticky=N+S+E+W)
Button(frame, text="=", command=sf.equals).grid(
        row=3, column=3, sticky=N+S+E+W)
Button(frame, text="fib", command=sf.fibIt).grid(
        row=5, column=3, sticky=N+S+E+W)
Button(frame, text="sqrt", command=sf.square_root).grid(
        row=4, column=3, sticky=N+S+E+W)
Button(frame, text=".", command=lambda: sf.press(".")).grid(
        row=5, column=2, sticky=N+S+E+W)
Button(frame, text="(", command=lambda: sf.press("(")).grid(
        row=6, column=0, sticky=N+S+E+W)
Button(frame, text=")", command=lambda: sf.press(")")).grid(
        row=6, column=1, sticky=N+S+E+W)
Button(frame, text="MOD", command=lambda: sf.press("%")).grid(
        row=6, column=2, sticky=N+S+E+W)

#Loops through all the rows and columns and resizes them if the
#window is resized.
for x in range(7):
    Grid.rowconfigure(frame, x, weight=1)
for y in range(4):
    Grid.columnconfigure(frame, y, weight=1)
