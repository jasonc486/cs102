#!/usr/bin/python
print( "Content-type: text/html\n\n" )
print( """
<html>
<body>
""" )
print("""<h1> My header </h1>
<table>
<tr><th>N</th><th>Nx100</th></tr>
""")
for x in range(1, 101):
	print("<tr> <td>%s</td> <td>%s</td> </tr>"%(x,x*100))
print( """
</table>
</body>
</html>
""" )
