from tkinter import *
root = Tk()
blockWidth = 50
blockHeight = 10
class MyCanvas(Canvas):
    def __init__(this, *args, **kwargs):
        Canvas.__init__(this, *args, **kwargs)
        this.ball = this.makeBall(50, 50)
        this.bind("<KeyPress>", this.keyWasPressed)
        this.focus_set()
        this.rectangle = this.makeRectangle(225,475)

    def makeBall(this, x, y, color="blue"):
        return this.create_oval(x, y, x + 5, y + 5, fill = color)
    def makeRectangle( this, x, y, color="red" ):
        return this.create_rectangle(x, y, x + blockWidth, y + blockHeight,
                                     fill = color)
    def eachFrame(this):
        sx, sy, ex, ey = this.coords(this.ball)
        print(sx, sy, ex, ey)
        this.move(this.ball, 1, 1)
    def keyWasPressed(this, event = None):
        key = event.keysym
        rx, ry, rex, rey = this.coords(this.rectangle)
        print("just pressed: ", key)
        if(key == "Left" and rx > 0):
            this.move(this.rectangle, -25, 0)
        elif(key == "Right" and rex < 500):
            this.move(this.rectangle, 25, 0)
        
canvas = MyCanvas(root, width = 500, height = 500)
canvas.pack()
while( True ):
    canvas.eachFrame()
    root.update()
