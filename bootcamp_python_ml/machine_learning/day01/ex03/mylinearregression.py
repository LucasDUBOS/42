import numpy as np

class MyLinearRegression():
    """
    Description:
        My personnal linear regression class to fit like a boss.
    """
    def __init__(self, theta):
        """
        Description:
            generator of the class, initialize self.
        Args:
            theta: has to be a list or a numpy array, it is a vector of
dimension (number of features + 1, 1).
        Raises:
            This method should noot raise any Exception.
        """
        self.theta = np.array(theta)

    def fit_(self, X, Y, alpha = 0.005, n_cycle = 1):
        n = X.shape[0] * X.shape[1]
        for i in range(n_cycle):
            bad_predict = self.predict_(X)
            D_m = (-2/n) * sum(X * (Y - bad_predict))  # Derivative wrt m
            D_c = (-2/n) * sum(Y - bad_predict)  # Derivative wrt c
            D_m = np.reshape(D_m,(D_m.shape[0],1))
            self.theta[1:] = self.theta[1:] - (alpha * D_m)  # Update m 
            self.theta[0] = self.theta[0] - (alpha * D_c)  # Update c
            # cost = self.cost_(X, Y)
            # print("cost : ", cost)


    def predict_(self, X):
        tab = []
        for j in range(X.shape[0]):
            i = 1
            tmp = int(self.theta[0])
            while i < X.shape[1] + 1:
                tmp += X[j][i - 1] * self.theta[i]
                i += 1
            tab.append(tmp)
        tab = np.array(tab)
        return tab

    def cost_elem_(self, X, Y):
        data = self.predict_(X) - Y
        data = data ** 2
        data = data / (Y.shape[0] * 2)
        return(data)

    def cost_(self, X, Y):
        data = sum(self.cost_elem_(X,Y))
        return(data)

    def mean(x):
        if len(x) == 0:
            return (None)
        tmp = 0.0
        for arg in x:
            tmp += arg
        tmp = tmp / len(x)
        return(tmp)

    def vec_mse(y, y_hat):
        if len(y) == 0:
            return (None)
        tmp = (y - y_hat) ** 2
        tmp = mean(tmp)
        return (tmp)

def main():
    X = np.array([[1., 1., 2., 3.], [5., 8., 13., 21.], [34., 55., 89., 144.]])
    Y = np.array([[23.], [48.], [218.]])
    mylr = MyLinearRegression([[1.], [1.], [1.], [1.], [1]])
    print(mylr.predict_(X))
    #array([[8.], [48.], [323.]])
    print(mylr.cost_elem_(X,Y))
    #array([[37.5], [0.], [1837.5]])
    print(mylr.cost_(X,Y))
    #1875.0
    print(mylr.theta)
    mylr.fit_(X, Y, alpha = 1.6e-4, n_cycle=200000)
    print(mylr.theta)
    #array([[18.023..], [3.323..], [-0.711..], [1.605..], [-0.1113..]])
    print(mylr.predict_(X))
    #array([[23.499..], [47.385..], [218.079...]])
    print(mylr.cost_elem_(X,Y))
    #array([[0.041..], [0.062..], [0.001..]])
    print(mylr.cost_(X,Y))
    #0.1056..

if __name__ == "__main__":
    main()