import pandas as pd
from FileLoader import FileLoader

def youngestFellah(data, year):
    data_year = data[data['Year'].eq(year)]
    data_f = data_year[data_year['Sex'].eq('F')]
    data_m = data_year[data_year['Sex'].eq('M')]
    print(data_f)
    dictionary = {
        'F': data_f.Age.min(),
        'M': data_m.Age.min()
    }
    print(dictionary)
    print("lol")
    # i = 0
    # tmp = 99
    # tmp1 = 99
    # while i < data.shape[0]:
    #     if data.loc[i,'Year'] == year and data.loc[i,'Sex'] == 'M' and tmp > data.loc[i,'Age']:
    #         tmp = data.loc[i,'Age']
    #     if data.loc[i,'Year'] == year and data.loc[i,'Sex'] == 'F' and tmp1 > data.loc[i,'Age']:
    #         tmp1 = data.loc[i,'Age']
    #     i += 1
    # print("{'f': " + str(tmp1) + ", 'm': " + str(tmp) + "}")


loader = FileLoader()
data = loader.load("../athlete_events.csv")

youngestFellah(data,2004)



