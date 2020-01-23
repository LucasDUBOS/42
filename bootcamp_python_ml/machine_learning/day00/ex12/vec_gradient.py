import numpy as np
 
def vec_gradient(x, y, theta):
    """Computes a gradient vector from three non-empty numpy.ndarray,
without any for-loop. The three arrays must have the compatible dimensions.
    Args:
    x: has to be an numpy.ndarray, a matrice of dimension m * n.
    y: has to be an numpy.ndarray, a vector of dimension m * 1.
    theta: has to be an numpy.ndarray, a vector n * 1.
    Returns:
    The gradient as a numpy.ndarray, a vector of dimensions n * 1, containg
the result of the formula for all j.
    None if x, y, or theta are empty numpy.ndarray.
    None if x, y and theta do not have compatible dimensions.
    Raises:
    This function should not raise any Exception.
    """
    data = x.dot(theta) - y #(Ho(Xi) - Yi)
    data = np.mat(data) * np.mat(x) #(data * Xi(j))
    data = data / x.shape[0] #1/m
    return (np.array(data).flatten()) #tableau np

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

    print("fonc 1" , vec_gradient(X, Y, Z))
    # array([ -37.35714286, 183.14285714, -393.        ])

    W = np.array([0,0,0])
    print("fonc 2" ,vec_gradient(X, Y, W))
    # array([ 0.85714286, 23.28571429, -26.42857143])

    print("fonc 3" ,vec_gradient(X, X.dot(Z), Z))


if __name__ == "__main__":
    main()