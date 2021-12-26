#!/usr/bin/python

#Jason Chen
#CS102 Fall 2020
#Homework 8
#10-28-2020

import cgi
import cgitb
cgitb.enable()

print( "Content-type: text/html\n\n" )
form = cgi.FieldStorage()
print( """<html>
<head>
<title>chart.py</title>
<script src="chart.js" type="text/javascript"></script>
<link rel="stylesheet" href="chart.css" type="text/css" />
</head>
<body>""" )

h=300
w=200

#Provided Constants
aCons = int(form["value_a"].value)
bCons = int(form["value_b"].value)
cCons = int(form["value_c"].value)
#delta x
dCons = int(cCons / 2)
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
print("""<h1 onClick="toggle()">Jason Chen - Click Me to Toggle</h1>""")

if (("value_a" and "value_b" and "value_c" in form) and
    cCons > 1 and aCons > 0 and bCons > 0):
    print("""<h1> Table Machine </h1>
    <table class="visible" id="testme">
    <tr> <th>x     </th> <th>y     </th> <th>yprime  </th> <th>sumy     </th> <th>fdoubleprime</th> </tr>
    """)
    i = 0;
    for x in range(-100, 101, dCons):
        colorm = "ColorRed"
        if i % 2 == 1:
            colorm = "ColorBlue"
        print("<tr class=%s> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td></tr>"%
            (colorm, x, y(x), yprime(x), ysum + yint(x), fdoubleprime(x)))
        i = i+1;
    print("""</table>""")
else:
  print( "<h1>You didn't give me all variables a, b, c!</h1>" )
print( """
</body>
</html>
""" )
