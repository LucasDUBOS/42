import numpy as np

def cost_elem_(theta, X, Y):
    data = predict_(theta,X) - Y
    data = data ** 2
    data = data / (Y.shape[0] * 2)
    return(data)

def cost_(theta, X, Y):
    return(sum(cost_elem_(theta,X,Y)))

# def vec_gradient(x, y, theta):
#     data = x.dot(theta) - y #(Ho(Xi) - Yi)
#     data = np.mat(data) * np.mat(x) #(data * Xi(j))
#     data = data / x.shape[0] #1/m
#     return (np.array(data).flatten()) #tableau np

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

def fit_(theta, X, Y, alpha = 1, n_cycle=1):
    """
    Description:
        Performs a fit of Y(output) with respect to X.
    Args:
        theta: has to be a numpy.ndarray, a vector of dimension (number of
features + 1, 1).
        X: has to be a numpy.ndarray, a matrix of dimension (number of
training examples, number of features).
        Y: has to be a numpy.ndarray, a vector of dimension (number of
training examples, 1).
    Returns:
        new_theta: numpy.ndarray, a vector of dimension (number of the
features +1,1).
        None if there is a matching dimension problem.
    Raises: 
    This function should not raise any Exception.
    """
    n = X.shape[0] * X.shape[1]
    for i in range(n_cycle):
        bad_predict = predict_(theta, X)
        D_m = (-2/n) * sum(X * (Y - bad_predict))  # Derivative wrt m
        D_c = (-2/n) * sum(Y - bad_predict)  # Derivative wrt c
        D_m = np.reshape(D_m,(D_m.shape[0],1))
        theta[1:] = theta[1:] - (alpha * D_m)  # Update m 
        theta[0] = theta[0] - (alpha * D_c)  # Update c
        # cost = cost_(theta, X, Y)
        # print("cost : ", cost)
    return(theta)

def main():

    X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    Y1 = np.array([[2.], [6.], [10.], [14.], [18.]])
    theta1 = np.array([[1.], [1.]])
    theta1 = fit_(theta1, X1, Y1, alpha = 0.01, n_cycle=2000)
    print(theta1)
    #array([[2.0023..],[3.9991..]])

    print("predict : ",predict_(theta1, X1))


    #array([2.0023..], [6.002..], [10.0007..], [13.99988..], [17.9990..])

    X2 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8.,
    80.]])
    Y2 = np.array([[19.6], [-2.8], [-25.2], [-47.6]])

    theta2 = np.array([[42.], [1.], [1.], [1.]])
    theta2 = fit_(theta2, X2, Y2, alpha = 0.0005, n_cycle=42000)
    print(theta2)
    
    
    #array([[41.99..],[0.97..], [0.77..], [-1.20..]])


    print("predict 2 ",predict_(theta2, X2))
    
    
    #array([[19.5937..], [-2.8021..], [-25.1999..], [-47.5978..]])
if __name__ == "__main__":
    main()