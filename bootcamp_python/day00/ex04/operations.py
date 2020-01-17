import sys

if len(sys.argv) != 3 or not sys.argv[1].isnumeric() or not sys.argv[2].isnumeric():
    print("InputError: must be 2 numbers")
    sys.exit(0)
a = int(sys.argv[1])
b = int(sys.argv[2])
print("sum:        ", a + b,"\nDifference: ",a - b ,"\nProduct:    ",a * b,"\nQuotient:   ",a / b,"\nRemainder:  ",a % b)
