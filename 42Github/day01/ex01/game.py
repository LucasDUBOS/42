# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 14:44:43 by lucdubos          #+#    #+#              #
#    Updated: 2020/01/14 15:29:56 by lucdubos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class GotCharacter:
    def __init__(self, first_name, is_alive = True):
        self.first_name = first_name
        self.is_alive = is_alive

class Stark(GotCharacter):
    def __init__(self, first_name=None, is_alive=True):
        super().__init__(first_name=first_name, is_alive=is_alive)
        self.family_name = "Stark"
        self.house_words = "Winter is Coming"

    def print_house_words(self):
        print(self.house_words)

    def die(self):
        self.is_alive = False



arya = Stark("Arya")
print(arya.__dict__)
print(arya.is_alive)
print(arya.family_name)
arya.die()
print(arya.is_alive)

