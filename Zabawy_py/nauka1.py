from Tkinter import *

okno = Tk()

topFrame = Frame(okno)
topFrame.pack(side = TOP, fill = X)

bootomFrame = Frame(okno)
bootomFrame.pack(side = BOTTOM)

labelka = Label(bootomFrame,text="Hello World!")
labelka.pack()

lab2 = Label(topFrame, text = "Labelka 2")
lab2.pack(side = LEFT)
przyciks = Button(topFrame, text="Nacisnij")
przyciks.pack(side=LEFT, fill=X)
okno.mainloop()