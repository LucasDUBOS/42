import sys

if len(sys.argv) == 1:
    sys.exit(0)
if len(sys.argv) > 2 or not sys.argv[1].isnumeric():
    print("ERROR")
    sys.exit(0)
if sys.argv[1] == 0:
    print("I'm Zero.")
elif int(sys.argv[1]) % 2 == 1:
    print("I'm Odd.")
else:
    print("I'm Even.")

