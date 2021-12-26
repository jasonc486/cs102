#!/usr/bin/python
print( "Content-type: text/html\n\n" )
print( """
<html>
<body>
""" )
print("""<h1> My header </h1>
<table>""")
for x in range(1, 101):
	print("<tr> <td>%s</td> <td>%s</td> </tr>"%(x,x-20))
print( """
</table>
</body>
</html>
""" )
