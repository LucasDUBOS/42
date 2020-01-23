import numpy as np

def predict_(theta, X):
    """
    Description:
    Prediction of output using the hypothesis function (linear model).
    Args:
    theta: has to be a numpy.ndarray, a vector of dimension (number of
    features + 1, 1).
    X: has to be a numpy.ndarray, a matrix of dimension (number of
    training examples, number of features).
    Returns:
    pred: numpy.ndarray, a vector of dimension (number of the training
    examples,1).
    None if X does not match the dimension of theta.
    Raises:
    This function should not raise any Exception.
    """
    if (theta.shape[0] - 1 != X.shape[1]):
        print("Incompatible dimension match between X and theta.")
        return(None)
    # tmp = theta[0]
    # theta = np.delete(theta, 0) # or slicing [0:] ?
    print("theta avant",theta)
    X = X * np.prod(theta[1:])
    print("X avant :",X)
    X = np.sum(X,axis =1) + int(theta[0])
    print("X apres :",X)
    X = np.reshape(X,(X.shape[0],1)) # in line
    print("X encore apres :",X)
    print("theta end", theta)
    return(X)

# def predict_(theta, X):
#     tab = []
#     for j in range(X.shape[0]):
#         i = 1
#         tmp = int(theta[0])
#         while i < X.shape[1] + 1:
#             tmp += X[j][i - 1] * theta[i]
#             i += 1
#         tab.append(tmp)
#     tab = np.array(tab)
#     return tab


def main():
    X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    theta1 = np.array([[2.], [4.]])
    print(predict_(theta1, X1))
    # array([[2], [6], [10], [14.], [18.]])

    # X2 = np.array([[1], [2], [3], [5], [8]])
    # theta2 = np.array([[2.]])
    # predict_(theta2, X2)

    # # Incompatible dimension match between X and theta.
    # # None
    X3 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8.,
    80.]])
    theta3 = np.array([[0.05], [1.], [1.], [1.]])
    print(predict_(theta3, X3))
    # array([[22.25], [44.45], [66.65], [88.85]])

if __name__ == "__main__":
    main()