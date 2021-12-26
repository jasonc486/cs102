#Jason Chen
#CS-102-E
#Cusack
import tkinter
tk = tkinter.Tk()
h=300
w=200
c = tkinter.Canvas( tk, width=w, height=h)
c.pack()
c.create_line(0, h/2, w, h/2)
c.create_line(w/2, 0, w/2, h)
#Provided Constants
aCons = 5
bCons = 4
cCons = 8
dCons = cCons / 2
#Functions
def y(x):
    return (aCons * ( x * x * x) - bCons * (x * x) + cCons * x);
def yprime(x):
    return (y(x)-y(x-dCons))/dCons;
def yint(x):
    return ((y(x) + y(x-dCons))/2)*dCons;
def fdoubleprime(x):
    return (yprime(x)-yprime(x-dCons))/dCons;
def scale(x):
    return x/(h/2);
#Makes Rectangles
def rectangler(func, scale, color):
    c.create_rectangle(x + w / 2, -(func) / scale + h / 2,
                       x + 1 + w / 2, -(func + 1) / scale + h / 2,
                       outline = color);
#Makes Scale Using Max
scaleY = scale(5040800);
scaleYprime = scale(156904);
scaleYsum = scale(559058656) + 10000;
scaleYDprime = scale(2872);
ysum = 0
#Main Loop
for x in range(-100, 101):
    ysum = ysum + yint(x)
    rectangler(y(x), scaleY, "blue")
    rectangler(yprime(x), scaleYprime, "red")
    rectangler(ysum, scaleYsum, "green")
    rectangler(fdoubleprime(x), scaleYDprime, "purple")
tk.mainloop()
