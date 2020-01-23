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

def gradient(x, y, theta):
    """Computes a gradient vector from three non-empty numpy.ndarray, using
a for-loop. The two arrays must have the compatible dimensions.
    Args:
    x: has to be an numpy.ndarray, a matrice of dimension m * n.
    y: has to be an numpy.ndarray, a vector of dimension m * 1.
    theta: has to be an numpy.ndarray, a vector n * 1.
    Returns:
    The gradient as a numpy.ndarray, a vector of dimensions n * 1.
    None if x, y, or theta are empty numpy.ndarray.
    None if x, y and theta do not have compatible dimensions.
    Raises:
    This function should not raise any Exception.
    """
    data = mat_vec_prod(x, theta)
    data = data - y
    print("result : ", data)
    tab = []
    for i in range(x.shape[1]):   
        tmp = 0.0
        for row, elem in zip(x, data):
            tmp += row[i] * elem
        tmp = tmp / x.shape[0]
        tab.append(tmp)
    tab = np.array(tab)
    print(tab)
    return (tab)
    
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

    print("fonc 1" , gradient(X, Y, Z))
    # array([ -37.35714286, 183.14285714, -393.        ])

    W = np.array([0,0,0])
    print("fonc 2" ,gradient(X, Y, W))
    # array([ 0.85714286, 23.28571429, -26.42857143])

    print("fonc 3" ,gradient(X, X.dot(Z), Z))


if __name__ == "__main__":
    main()