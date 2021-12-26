
# Jason Chen
# CS102 Fall 2020
# Homework 12
# 12/9/2020

from intersect import *
from tkinter import *
import time
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
        this.ball_velocity_x = 1
        this.ball_velocity_y = 1
        this.bind( "<Motion>", this.mouseHasMoved )
        for i in range( 100, 400, 75):
            for j in range(100, 350, 50):
                this.makeBlock(i, j)
    def mouseHasMoved( this, event ):
        rx, ry, rex, rey = this.coords(this.rectangle)
        #print( event.x, event.y )
        if(rx > event.x and rx > 0):
            this.move(this.rectangle, event.x - rx, 0)
        if(rx < event.x and rex < 500):
            this.move(this.rectangle, event.x - rx, 0)    
    def makeBall(this, x, y, color="blue"):
        return this.create_oval(x, y, x + 5, y + 5, fill = color)
    def makeRectangle( this, x, y, color="red" ):
        return this.create_rectangle(x, y, x + blockWidth, y + blockHeight,
                                     fill = color)
    def makeBlock(this, x, y, color = "orange"):
        return this.create_rectangle(x, y, x + blockWidth, y + blockHeight
                                     , tags="block", fill = color )
    def eachFrame(this):
        sx, sy, ex, ey = this.coords(this.ball)
        #print(sx, sy, ex, ey)
        rx, ry, rex, rey = this.coords(this.rectangle)
        allblocks = this.find_withtag( "block" )
        for block in allblocks:
            sx1, sy1, ex1, ey1 = this.coords(block)
            if ('N' in hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey)):
                print(hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey))
                this.ball_velocity_y = -abs(this.ball_velocity_y)
            if ('E' in hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey)):
                print(hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey))
                this.ball_velocity_x = abs(this.ball_velocity_x)
            if ('S' in hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey)):
                print(hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey))
                this.ball_velocity_y = abs(this.ball_velocity_y)
            if ('W' in hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey)):
                print(hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey))
                this.ball_velocity_x = -abs(this.ball_velocity_x)
            if (not [] == hits(sx1, sy1, ex1, ey1, sx, sy, ex, ey)):
                this.delete(block)
        if(len(allblocks) == 0):
            raise(Exception("You Win!!!"))
        this.move(this.ball, this.ball_velocity_x, this.ball_velocity_y)
        if (sx <= 0):
            this.ball_velocity_x = abs(this.ball_velocity_x)
        if (ex >= 500):
            this.ball_velocity_x = -abs(this.ball_velocity_x)
        if (sy <= 0):
            this.ball_velocity_y = abs(this.ball_velocity_y)
        #if (ey >= 500):
        #    this.ball_velocity_y = -abs(this.ball_velocity_y)

        if((sx <= rex and ex >= rx) and ey > ry):
            this.ball_velocity_y = -abs(this.ball_velocity_y)

        if(ey > 500):
            raise(Exception("You lose!!!"))

    def keyWasPressed(this, event = None):
        key = event.keysym
        rx, ry, rex, rey = this.coords(this.rectangle)
        #print("just pressed: ", key)
        if(key == "Left" and rx > 0):
            this.move(this.rectangle, -25, 0)
        elif(key == "Right" and rex < 500):
            this.move(this.rectangle, 25, 0)
        
        
        
canvas = MyCanvas(root, width = 500, height = 500)
canvas.pack()
while( True ):
    canvas.eachFrame()
    root.update()
    time.sleep(.005)
