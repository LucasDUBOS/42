import numpy as np

def predict_(theta, X):
    if (theta.shape[0] - 1 != X.shape[1]):
        print("Incompatible dimension match between X and theta.")
        return(None)
    tmp = theta[0]
    theta = np.delete(theta, 0) # or slicing [0:] ?
    X = X * np.prod(theta)
    X = np.sum(X,axis =1) + tmp
    X = np.reshape(X,(X.shape[0],1)) # in line
    return(X)


def cost_elem_(theta, X, Y):
    """
    Description:
    Calculates all the elements 0.5*M*(y_pred - y)^2 of the cost
function.
    Args:
    theta: has to be a numpy.ndarray, a vector of dimension (number of
features + 1, 1).
    X: has to be a numpy.ndarray, a matrix of dimension (number of
training examples, number of features).
    Returns:
    J_elem: numpy.ndarray, a vector of dimension (number of the training
examples,1).
    None if there is a dimension matching problem between X, Y or theta.
    Raises:
    This function should not raise any Exception.
    """
    data = predict_(theta,X) - Y
    data = data ** 2
    data = data / (Y.shape[0] * 2)
    return(data)

def cost_(theta, X, Y):
    """
    Description:
        Calculates the value of cost function.
    Args:
        theta: has to be a numpy.ndarray, a vector of dimension (number of
features + 1, 1).
        X: has to be a numpy.ndarray, a vector of dimension (number of
training examples, number of features).
    Returns:
        J_value : has to be a float.
        None if X does not match the dimension of theta.
    Raises:
        This function should not raise any Exception.
    """
    return(sum(cost_elem_(theta,X,Y)))

def main():
    X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    theta1 = np.array([[2.], [4.]])
    Y1 = np.array([[2.], [7.], [12.], [17.], [22.]])
    print(cost_elem_(theta1, X1, Y1))
    #array([[0.], [0.1], [0.4], [0.9], [1.6]])
    print(cost_(theta1, X1, Y1))
    #3.0
    X2 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8.,
    80.]])
    theta2 = np.array([[0.05], [1.], [1.], [1.]])
    Y2 = np.array([[19.], [42.], [67.], [93.]])
    print(cost_elem_(theta2, X2, Y2))
    #array([[1.3203125], [0.7503125], [0.0153125], [2.1528125]])
    print(cost_(theta2, X2, Y2))
    #4.238750000000004


    # M = 5
    # Total = 10
    # print("test4 =", Total * (M * 2))
    # print("test1 = ", (0.5 * M) * Total)
    # print("test2 =", (0.5 / M) * Total)
    # print("test3 =", Total / (M * 2))

if __name__ == "__main__":
    main()