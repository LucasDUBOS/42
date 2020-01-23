import numpy as np

def mat_vec_prod(x, y): #y = index
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

def mean(x):
    if len(x) == 0:
        return (None)
    tmp = 0.0
    for arg in x:
        tmp += arg
    tmp = tmp / len(x)
    return(tmp)

def linear_mse(x, y, theta):
    """Computes the mean squared error of three non-empty numpy.ndarray,
using a for-loop. The three arrays must have compatible dimensions.
    Args:
    y: has to be an numpy.ndarray, a vector of dimension m * 1.
    x: has to be an numpy.ndarray, a matrix of dimesion m * n.
    theta: has to be an numpy.ndarray, a vector of dimension n * 1.
    Returns:
    The mean squared error as a float.
    None if y, x, or theta are empty numpy.ndarray.
    None if y, x or theta does not share compatibles dimensions.
    Raises:
    This function should not raise any Exception.
    """
    tmp = mat_vec_prod(x,theta)
    print("test:",tmp)
    tmp = mean((tmp - y) ** 2)
    return (tmp)


def main():
    X = np.array([
        [ -6, -7, -9],
            [ 13, -2, 14],
            [ -7, 14, -1],
            [ -8, -4, 6],
            [ -5, -9, 6],
            [ 1, -5, 11],
            [ 9, -11, 8]])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    Z = np.array([3,0.5,-6])
    print(linear_mse(X, Y, Z))
    #2641.0

    W = np.array([0,0,0])
    print(linear_mse(X, Y, W))
    #130.71428571

if __name__ == "__main__":
    main()