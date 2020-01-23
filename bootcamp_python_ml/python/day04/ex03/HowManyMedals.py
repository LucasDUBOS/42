import pandas as pd
from FileLoader import FileLoader

def howManyMedals(data, name):
    data = data[data['Name'] == name]
    # print(data)
    answer = {}
    tmp = 0
    for index, row in data.iterrows():
        if not row['Year'] == tmp:
            tmp = row['Year']
            tmp_data = data[data['Year'] == row['Year']]
            gold = tmp_data[tmp_data['Medal'] == 'Gold'].shape[0]
            silver = tmp_data[tmp_data['Medal'] == 'Silver'].shape[0]
            bronze = tmp_data[tmp_data['Medal'] == 'Bronze'].shape[0]
            answer[tmp] = {
                'G' : gold, 
                'S' : silver, 
                'B' : bronze
            }
    print(answer)
    
# petitdict = {'a': 4, 'b': 3}
# mydict = {}
# mydict['1922'] = petitdict

# print (mydict)

# print(data)



loader = FileLoader()
data = loader.load("../athlete_events.csv")

howManyMedals(data, "Kjetil Andr Aamodt")
