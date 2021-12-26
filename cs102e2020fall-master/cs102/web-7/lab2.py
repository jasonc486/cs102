#!/usr/bin/python
print( "Content-type: text/html\n\n" )
print( """
<html>
<body>
""" )
print("<h1> My header </h1>")
for x in range(1, 101):
	print("<p>%s</p>"%(x))
print( """
</body>
</html>
""" )
