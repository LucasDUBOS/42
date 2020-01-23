import pandas as pd

class FileLoader:
    def load(self, path):
        data = pd.read_csv(path)
        print("Loading dataset of dimensions", data.shape[0], "x", data.shape[1])
        return data

    def display(self, data, n):
        print(data[:n]) if n >= 0 else print(data[n:]) 

def main():
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    loader.display(data, 15)

if __name__ == "__main__":
    main()



