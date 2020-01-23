import numpy as np

def mat_vec_prod(x, y): #y = index
    """Computes the product of two non-empty numpy.ndarray, using a
for-loop. The two arrays must have compatible dimensions.
    Args:
    x: has to be an numpy.ndarray, a matrix of dimension m * n.
    y: has to be an numpy.ndarray, a vector of dimension n * 1.
    Returns:
    The product of the matrix and the vector as a vector of dimension m *
1.
    None if x or y are empty numpy.ndarray.
    None if x and y does not share compatibles dimensions.
    Raises:
    This function should not raise any Exception.
    """
    print("prod")
    f = lambda f, r : f * r
    tab = []
    for row in x:
        tmp = 0.0
        for argx, arg1 in zip(row, y):
            tmp += f(argx , arg1)
        tab.append(tmp)
    if (len(x) == 0):
        print("bug")
        return(None)
    tab = np.array(tab)
    return(tab)



def main():
    W = np.array([
        [ -8, 8, -6, 14, 14, -9, -4],
        [ 2, -11, -2, -11, 14, -2, 14],
        [-13, -2, -5, 3, -8, -4, 13],
        [ 2, 13, -14, -15, -14, -15, 13],
        [ 2, -1, 12, 3, -7, -3, -6]])

    X = np.array([0, 15, -9, 7, 12, 3, -21]).reshape((7,1))
    Y = np.array([2, 14, -13, 5, 12, 4, -19]).reshape((7,1))
    print("tab :")
    print(mat_vec_prod(W, X))
    print("tab :")
    print(mat_vec_prod(W, Y))
    print("go")

if __name__ == "__main__":
    main()