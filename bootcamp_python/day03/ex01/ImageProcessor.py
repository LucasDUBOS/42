import numpy as np
from matplotlib.image import imread
import matplotlib.pyplot as plt


"""
 load = sort un array type numpy d une image 
 display = ressort l image a partir du tableau RGB 
"""
def load(path):
    img = imread('42AI.png')
    print("the image size :" , img.shape[0], "x" , img.shape[1])
    return (img)

def display(image):
    plt.imshow(image)
    plt.show()


tab_numpy = load('42AI.png')
print(tab_numpy)


display(tab_numpy)


