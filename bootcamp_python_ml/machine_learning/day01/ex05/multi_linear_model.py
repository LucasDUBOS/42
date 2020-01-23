import numpy as np
from sklearn.metrics import mean_squared_error
import pandas as pd
from mylinearregression import MyLinearRegression as MyLR
import matplotlib.pyplot as plt
from math import cos, pi


def main():


    data = pd.read_csv("spacecraft_data.csv")

    X = np.array(data[['Age','Thrust_power','Terameters']])
    Y = np.array(data[['Sell_price']])

    # myLR_age = MyLR([[700.0], [-30.0]])
    # # print(myLR_age.theta)

    # myLR_age.fit_(X[:,0].reshape(-1,1), Y, alpha = 2.5e-5, n_cycle = 100)
    # RMSE_age = myLR_age.mse_(myLR_age.predict_(X[:,0].reshape(-1,1)),Y)
    # # print(myLR_age.theta)
    # # print(RMSE_age)

    # plt.title("Evolution of the sell price of spacecrafts with respect to the age of the spacecraft\nand representation of the predicted values of our first model.", fontsize = 8)
    # plt.ylabel("sell price")
    # plt.xlabel("age")

    # # print(X[:,0].reshape(-1,1))
    # # print("predict : ",myLR_age.predict_(X[:,0].reshape(-1,1)))


    # # plt.plot(X[:,0].reshape(-1,1), Y, 'bo', X[:,0].reshape(-1,1),myLR_age.predict_(X[:,0].reshape(-1,1)), 'go')
    # # plt.show()

    # # print(X[:,1].reshape(-1,1))
    # myLR_thrust = MyLR([[15.3],[4.4]])
    # myLR_thrust.fit_(X[:,1].reshape(-1,1), Y, alpha = 2.5e-5, n_cycle = 200)
    # # print(myLR_thrust.mse_(myLR_thrust.predict_(X[:,0].reshape(-1,1)),Y))
    # # print(myLR_thrust.theta)

    # plt.title("Evolution of the sell price of spacecrafts with respect to the thrust power\nof the spacecraft engines and representation of the predicted values of our second model.", fontsize = 8)
    # plt.ylabel("sell price")
    # plt.xlabel("thrust")

    # # plt.plot(X[:,1].reshape(-1,1), Y, 'bo', X[:,1].reshape(-1,1),myLR_thrust.predict_(X[:,1].reshape(-1,1)), 'go')
    # # plt.show()

    # # print(X[:,1].reshape(-1,1))
    # myLR_dist = MyLR([[0.0],[1.5]])
    # myLR_dist.fit_(X[:,2].reshape(-1,1), Y, alpha = 0.0005, n_cycle = 5)
    # # print(myLR_thrust.mse_(myLR_thrust.predict_(X[:,0].reshape(-1,1)),Y))
    # # print(myLR_thrust.theta)

    # plt.title("Evolution of the sell price of spacecrafts\nwith respect to the terameters driven and the predicted values of our third model.", fontsize = 8)
    # plt.ylabel("sell price")
    # plt.xlabel("distance")
    # # plt.plot(X[:,2].reshape(-1,1), Y, 'bo',myLR_dist.predict_(X[:,2].reshape(-1,1)),Y ,'go')
    # # plt.show()


    my_lreg = MyLR([360.3584, -23.438, 5.7636, -2.6267])
    # print(my_lreg.predict_(X))
    # print(my_lreg.mse_(Y,my_lreg.predict_(X)))

    my_lreg.fit_(X,Y, alpha = 1e-4, n_cycle = 60)
    print(my_lreg.theta)



    
    print(my_lreg.mse_(Y,my_lreg.predict_(X)))


    plt.title("Evolution of the sell prices of spacecrafts and evolution of predicted sell prices\nof spacecrafts with the multi-variables hypothesis, with respect to the age.", fontsize = 8)
    plt.ylabel("sell price")
    plt.xlabel("age")
    plt.plot(X[:,0], Y, 'bo', X[:,0], my_lreg.predict_(X), 'go')
    plt.show()

    plt.plot(X[:,1], Y, 'bo', X[:,1], my_lreg.predict_(X), 'go')
    plt.show()

    plt.plot(X[:,2], Y, 'bo', X[:,2], my_lreg.predict_(X), 'go')
    plt.show()








    # data = pd.read_csv("are_blue_pills_magics.csv")

    # Xpill = np.array(data["Micrograms"]).reshape(-1,1)
    # Yscore = np.array(data["Score"]).reshape(-1,1)


    # mlr = MyLR([[1.0], [1.0]])
    # mlr.fit_(Xpill, Yscore, alpha = 0.005, n_cycle=2000)
    # best_theta = mlr.theta
    # print(best_theta)

    # better_y_score = mlr.predict_(Xpill)
    # print(better_y_score)

    # plt.title("Evolution of the space driving score in function of the quantity of blue pill (in micrograms). \nIn blue the real values and in green the predicted values.", fontsize = 8)
    # plt.xlabel("micrograms")
    # plt.ylabel("Score")
    # plt.plot(Xpill, Yscore, 'bo', Xpill, better_y_score, 'g-.', Xpill, better_y_score, "go")
    # plt.show()

    # plt.close()








    # linear_model1 = MyLinearRegression(np.array([[89.0], [-6]]))
    # linear_model2 = MyLinearRegression(np.array([[89.0], [-6]]))
    # Y_model1 = linear_model1.predict_(Xpill)
    # Y_model2 = linear_model2.predict_(Xpill)

    # print(linear_model1.mse_(Y_model1, Yscore))
    # # 57.60304285714282
    # print(mean_squared_error(Y_model1, Yscore))
    # # 57.603042857142825
    # print(linear_model2.mse_(Y_model2, Yscore))
    # print("cost = ", linear_model2.cost_(Xpill, Yscore))
    # # 232.16344285714285
    # print(mean_squared_error(Y_model2, Yscore))
    # # # 232.16344285714285


    # x = []
    # y = [] # On a créé deux listes vides pour contenir les abscisses et les ordonnées
    # move_theta = -14.0
    # for i in range(1000): # On veut les points de 0 à 100
    #     linear_model1 = MyLinearRegression(np.array([[88.0], [move_theta]]))
    #     # for i in range(5):
    #     Y_model1 = linear_model1.predict_(Xpill)
    #     y.append(float(linear_model1.cost_(Xpill, Yscore)))
    #     x.append(float(linear_model1.theta[1]))
    #     move_theta += 0.01
    #     # linear_model1.fit_(Xpill, Yscore, alpha = 0.00005, n_cycle=10)
    # plt.plot(x, y)
    # plt.show()
    # plt.close()



if __name__ == "__main__":
    main()