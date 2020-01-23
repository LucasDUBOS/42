import sys

i = 0
str = ""
for arg in sys.argv[1:]:
    if i != 0:
       str = str + " " + arg
    else: 
       str = str + arg
    i += 1
print(str[::-1].swapcase())
