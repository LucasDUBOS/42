import numpy as np
from PIL import Image
from matplotlib.image import imread
import matplotlib.pyplot as plt

def load(filename):
    img = np.array(Image.open(filename))
    print("the image size :" , img.shape[0], "x" , img.shape[1])
    return (img)

def display(image):
    plt.imshow(image)
    plt.show()

class ColorFilter():
    def invert(self, array):
        return 1 - array
    
    def to_blue(self, array):
        i = 0
        while i < array.shape[0]:
            j = 0
            while(j < array.shape[1]):
                array[i][j][2] = 255
                j += 1
            i += 1

def main():
    # tab_numpy = load('../ex01/42AI.png')
    tab_numpy = load('musk_weed.jpg')
    filter = ColorFilter()

    tab_2x3_pixel = np.zeros((5,2,3), dtype=int)
    

    print(tab_numpy.shape)
    # display(tab_2x3_pixel)

    print(tab_2x3_pixel.shape)

    filter.to_blue(tab_2x3_pixel)
    display(tab_2x3_pixel)
    print(tab_2x3_pixel)

    # tab_numpy.setflags(write=1)
    print(type(tab_numpy))
    # display(tab_numpy)

    # print(tab_numpy.flags)


    filter.to_blue(tab_numpy)
    print(tab_numpy)
    display(tab_numpy)


if __name__ == "__main__":
    main()