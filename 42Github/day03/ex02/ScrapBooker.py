import numpy as np
from matplotlib.image import imread
import matplotlib.pyplot as plt

def load(path):
    img = imread(path)
    print("the image size :" , img.shape[0], "x" , img.shape[1])
    return (img)

def display(image):
    plt.imshow(image)
    plt.show()

class ScrapBooker():
    def crop(self, array, dimensions=(1,1), position=(0,0)):
        if dimensions[0] > array.shape[0] or dimensions[1] > array.shape[1]:
            print("Error, new dimension is too big")
            exit()
        cropped = array[position[0]:dimensions[0] + position[0],position[1]:dimensions[1] + position[1]]
        return cropped
    
    def thin(self, array, n, axis):
        # print(list(range(0, array.shape[axis], n)))
        return np.delete(array,list(range(0, array.shape[axis], n)), axis=axis)

    def juxtapose(self, array, n, axis):
        fulltab = array
        for i in range(n - 1):
            fulltab = np.concatenate((fulltab, array), axis=axis)
        return fulltab
    
    def mosaic(self, array, dimensions):
        fulltab = self.juxtapose(array, dimensions[0], 0)
        return self.juxtapose(fulltab, dimensions[1], 1)


def main():
    tab_numpy = load('../ex01/42AI.png')
    # display(tab_numpy)

    test = ScrapBooker()

    # display(test.crop(tab_numpy, (50,50), (50,50)))

    # display(test.thin(tab_numpy, 2, 0))

    # display(test.juxtapose(tab_numpy, 5, 1))

    display(test.mosaic(tab_numpy, (5,10)))


if __name__ == "__main__":
    main()