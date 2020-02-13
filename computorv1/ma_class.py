class polynome_class:
    def __init__(self, chaine):
        self.signe = "+"
        self.flag_egal = 1
        self.tab = []
        self.parse_elem(chaine)
    
    def fonction(self, elem, char):
        if elem == "":
            return -1       
        signe = 1 if self.signe == "+" or self.signe == '=' else -1
        signe *= self.flag_egal 
        index = 0
        while index < len(elem) and (elem[index] == "+" or elem[index] == '-'):
            signe = signe * -1 if elem[index] == '-' else signe * 1
            index +=1
        elem = elem[index:]
        index = 0
        while index < len(elem) and elem[index] != "X":
            index += 1
        if index == len(elem):
            if len(self.tab) < 1:
                self.tab.append(int(elem))
            else:
                self.tab[0] += (float(elem))
        else:
            nb = int(elem[(index + 2):])
            while len(self.tab) <= nb:
                self.tab.append(0)
            self.tab[int(elem[index + 2:])] += float(elem[:(index - 2)]) * signe 
        if char == '=':
            self.flag_egal = -1
        self.signe = char
        return 1

    def parse_elem(self, chaine):
        index = 0
        while index < len(chaine) and chaine[index]:
            tmp = index
            while (index < len(chaine) and chaine[index] != "+" and chaine[index] != "-" and chaine[index] != "="):
                index += 1
            if (index == len(chaine)):
                if self.fonction(chaine[tmp:index], "+") == -1:
                    if self.signe == "+":
                        self.signe = "-"
                    else:
                        self.signe = "+"
            else:
                if self.fonction(chaine[tmp:index - 1], chaine[index]) == -1:
                    if self.signe == "+":
                        self.signe = "-"
                    else:
                        self.signe = "+"
            index += 1
