import tkinter
tk = tkinter.Tk()
c = tkinter.Canvas( tk, width=400, height=600 )
c.pack()

#c.create_rectangle(30, 450, 300, 40);

def eq(x):
    return 1 + x * x;
scale = 70
for x in range(-200, 201):
    c.create_rectangle( x, eq(x)/scale, x+1, (eq(x)+1)/scale );
    #print(eq(x));
tk.mainloop()
