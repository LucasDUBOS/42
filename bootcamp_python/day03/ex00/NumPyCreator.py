import numpy as np


class NumPyCreator():
    # def __init__(self, arg):



    def from_list(self,lst):
        return np.array(lst)

    def from_tuple(self, tup):
        return np.asarray(tup)

    def from_iterable(self, itr):
        return np.array(itr)

    def from_shape(self, shape):
        return np.zeros(shape, dtype=int)
    
    def random(self, shape):
        # print(np.random(0,1,2))
        return np.random.random_sample(shape)

    def identity(self, n):
        return np.identity(n)

npc = NumPyCreator()


lst = [[1, 2, 3], [4, 5, 6]]
tup = ((1 , 2 , 3), (4,5,6))

print("lst :\n" , npc.from_list(lst))
# test = npc.from_list(lst)
# print(lst[0,1])
# print(test[0,1])
print("tup :\n" , npc.from_tuple(tup))
print("itr :\n" , npc.from_iterable(range(5)))
shape=(3,5)
print("shape :\n", npc.from_shape(shape))
print("random :\n", npc.random(shape))
print("identity :\n", npc.identity(4))






