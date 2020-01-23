import numpy as np

def mse(x, y_hat):
    """Computes the mean squared error of two non-empty numpy.ndarray, using
a for-loop. The two arrays must have the same dimensions.
    Args:
    y: has to be an numpy.ndarray, a vector.
    y_hat: has to be an numpy.ndarray, a vector.
    Returns:
    The mean squared error of the two vectors as a float.
    None if y or y_hat are empty numpy.ndarray.
    None if y and y_hat does not share the same dimensions.
    Raises:
    This function should not raise any Exception.
    """
    if len(x) == 0:
        return (None)
    tmp = 0.0
    for arg, arg1 in zip(x, y_hat):
        tmp += (arg - arg1) ** 2
    tmp = tmp / len(x)
    return(tmp)


def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    print(mse(X, Y))
    #4.285714285714286
    print(mse(X, X))
    #0.0

if __name__ == "__main__":
    main()