import numpy as np

def sum_(x, f):
    """Computes the sum of a non-empty numpy.ndarray onto wich a function is
applied element-wise, using a for-loop.
    Args:
     x: has to be an numpy.ndarray, a vector.
     f: has to be a function, a function to apply element-wise to the
vector.
    Returns:
     The sum as a float.
     None if x is an empty numpy.ndarray or if f is not a valid function.
    Raises:
     This function should not raise any Exception.
    """
    tmp = 0.0
    for arg in x:
        tmp += f(arg)
    if (len(x) == 0 or f.__name__ != "<lambda>"): #revoir f.__name__ c'est pas ouf
        print("bug")
        return(None)
    return(tmp)
    
def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])

    x = lambda x : x
    print(isinstance(x, int))
    print(type(x))
    print(x(3))

    print(sum_(X, lambda x: x * x))
    print(sum_(X, lambda x: x**2))

    x = lambda x : x ** 2 # ** = exponentielle
    print(x(7))

if __name__ == "__main__":
    main()