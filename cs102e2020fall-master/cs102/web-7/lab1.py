#!/usr/bin/python
print( "Content-type: text/html\n\n" )
print( """
<html>
<body>
""" )
for x in range(0, 100):
	print("<h1>Hello, world!</h1>")
print( """
</body>
</html>
""" )
