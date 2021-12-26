#!/usr/bin/python

import cgi
import cgitb
cgitb.enable()

print( "Content-type: text/html\n\n" )

print( """<html>
<head>
<title>lab7.py</title>
<script src="lab7.js" type="text/javascript"></script>
<link rel="stylesheet" href="lab7.css" type="text/css" />
</head>
<body>""" )

form = cgi.FieldStorage()
print("""<h1 onClick="toggle()">clicky me likey</h1>""")
print( '<h1 class="invisible" id="testme">Hi, ' + form["firstname"].value + "</h1>" )
if "firstname" in form:
  print( '<h1 class="invisible" id="testme">Hi, ' + form["firstname"].value + "</h1>" )
else:
  print( "<h1>You didn't give me a name!</h1>" )

print( "</body></html>" )
