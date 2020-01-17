import sys
import string

def text_analyzer(*list):
    """
This function counts the number of upper characters, lower characters,
 punctuation and spaces in a given text.
    """
    str = ""
    if len(list) == 0:
        str = input("What is the text to analyse ?\n")
    else:
        for arg in list:
            str = str + arg
    space = 0
    upper = 0
    lower = 0
    punctuation = 0
    for c in str:
        if c.isupper():
            upper += 1
        elif c.islower():
            lower += 1
        elif c in string.punctuation:
            punctuation += 1
        elif c == " ":
            space += 1
    print("The text contains", len(str),"characters:\n-", upper,"upper letters\n-",lower ,"lower letters\n-", punctuation,"punctuation marks\n-",space,"spaces")
