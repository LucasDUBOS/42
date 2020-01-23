import pandas as pd
from FileLoader import FileLoader

"""

COMPARE WITH :


def proportionBySport(df, year, sport, gender):
    total_players = df.loc[(df['Year']==year) & (df['Sex']==gender)]['Name'].unique().shape[0]
    total_sport = df.loc[(df['Sport']==sport) & (df['Year']==year) & (df['Sex']==gender)]['Name'].unique().shape[0]
    return total_sport / total_players


"""



def proportionBySport(data, year, sport, gender):

    data = data[data['Sex'] == gender] #nb femme
    data_cpy = data[data['Year'] == year] #nb femme 2004
    data = data_cpy[data_cpy['Sport'] == sport] #nb tenniswoman

    data_cpy.drop_duplicates(subset="Name",keep = False, inplace=True) #supr doublon nb joueur
    data = data.drop_duplicates(subset="Name",keep = False) #supr doublon nb tenniswoman

    nb_participant = len(data_cpy)
    nb_echantillon = len(data)

    print("echantillon :", nb_echantillon, "nb participant", nb_participant)
    print(nb_echantillon / nb_participant)



loader = FileLoader()
data = loader.load("../athlete_events.csv")

proportionBySport(data, 2004, 'Tennis', 'F')