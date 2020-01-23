import numpy as np
from sklearn.metrics import mean_squared_error
import pandas as pd
from mylinearregression import MyLinearRegression
import matplotlib.pyplot as plt
from math import cos, pi


# import sys
# sys.path.append("..") # Adds higher directory to python modules path.
# import numpy as np
# import sys
# sys.path.append(../ex03/mylinearregression.py)
# from ..ex03.mylinearregression import MyLinearRegression as My
# from Users.lucdubos.bootcamp_python_ml.machine_learning.day01.ex03 import mylinearregression
# import Users.lucdubos.bootcamp_python_ml.machine_learning.day01.ex03.mylinearregression

# from ..ex03.mylinearregression import MyLinearRegression as My



def main():
    data = pd.read_csv("are_blue_pills_magics.csv")

    Xpill = np.array(data["Micrograms"]).reshape(-1,1)
    Yscore = np.array(data["Score"]).reshape(-1,1)

    mlr = MyLinearRegression([[1.0], [1.0]])
    mlr.fit_(Xpill, Yscore, alpha = 0.005, n_cycle=2000)
    best_theta = mlr.theta
    print(best_theta)

    better_y_score = mlr.predict_(Xpill)
    print(better_y_score)

    plt.title("Evolution of the space driving score in function of the quantity of blue pill (in micrograms). \nIn blue the real values and in green the predicted values.", fontsize = 8)
    plt.xlabel("micrograms")
    plt.ylabel("Score")
    plt.plot(Xpill, Yscore, 'bo', Xpill, better_y_score, 'g-.', Xpill, better_y_score, "go")
    plt.show()

    plt.close()








    linear_model1 = MyLinearRegression(np.array([[89.0], [-6]]))
    linear_model2 = MyLinearRegression(np.array([[89.0], [-6]]))
    Y_model1 = linear_model1.predict_(Xpill)
    Y_model2 = linear_model2.predict_(Xpill)

    print(linear_model1.mse_(Y_model1, Yscore))
    # 57.60304285714282
    print(mean_squared_error(Y_model1, Yscore))
    # 57.603042857142825
    print(linear_model2.mse_(Y_model2, Yscore))
    print("cost = ", linear_model2.cost_(Xpill, Yscore))
    # 232.16344285714285
    print(mean_squared_error(Y_model2, Yscore))
    # # 232.16344285714285


    x = []
    y = [] # On a créé deux listes vides pour contenir les abscisses et les ordonnées
    move_theta = -14.0
    for i in range(1000): # On veut les points de 0 à 100
        linear_model1 = MyLinearRegression(np.array([[88.0], [move_theta]]))
        # for i in range(5):
        Y_model1 = linear_model1.predict_(Xpill)
        y.append(float(linear_model1.cost_(Xpill, Yscore)))
        x.append(float(linear_model1.theta[1]))
        move_theta += 0.01
        # linear_model1.fit_(Xpill, Yscore, alpha = 0.00005, n_cycle=10)
    plt.plot(x, y)
    plt.show()
    plt.close()



if __name__ == "__main__":
    main()