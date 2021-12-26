#!/usr/bin/python

#Jason Chen
#CS102 Fall 2020
#Homework 7
#10-14-2020

h=300
w=200

#Provided Constants
aCons = 5
bCons = 4
cCons = 8
#delta x
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

#Makes Scale Using Max
scaleY = scale(5040800);
scaleYprime = scale(156904);
scaleYsum = scale(559058656) + 10000;
scaleYDprime = scale(2872);
ysum = 0
#Main Loop
print( "Content-type: text/html\n\n" )
print( """
<html>
<body>
""" )
print("""<h1> My header </h1>
<table>
<tr> <th>x     </th> <th>y     </th> <th>yprime  </th> <th>sumy     </th> <th>fdoubleprime</th> </tr>
""")
for x in range(-100, 101, dCons):
    print("<tr> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td></tr>"%
         (x, y(x), yprime(x), ysum + yint(x), fdoubleprime(x)))
print( """
</table>
</body>
</html>
""" )
