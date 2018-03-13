from Tkinter import *

#alt1
#def printName():
#    print("Jestem Wojtek!")

#alt2
def printName(event):
    print("Jestem Wojtek!")

mainW = Tk()

#widgety
lab1 = Label(mainW,text = "Nazwa:")
lab2 = Label(mainW,text="Haslo:")
ent1 = Entry(mainW)
ent2 = Entry(mainW)
#alt1
#but1 = Button(mainW,text="Wyslij",command=printName)
#alt2
but1 = Button(mainW,text="Wyslij")
c1 = Checkbutton(mainW,text="Zapamietaj")

#eventy
but1.bind("<Button-1>",printName)

#layout
#sticky = N W E S - strony swiata
lab1.grid(row=0,column=0,sticky=E)
lab2.grid(row=1,column=0,sticky=E)
ent1.grid(row=0,column=1)
ent2.grid(row=1,column=1)
but1.grid(row=3,column=3)
c1.grid(row=3,column=0,columnspan=2)

mainW.mainloop()