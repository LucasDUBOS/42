# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 10:33:00 by lucdubos          #+#    #+#              #
#    Updated: 2020/01/14 12:39:03 by lucdubos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class recipe:
    def __init__(self, name, cooking_lvl = 0, cooking_time = 0, ingredients = [], description = None, recipe_type = ""):
        if type(name) != str and type(cooking_lvl) != int and type(cooking_time) != int and type(ingredients) != list and type(recipe_type) != str:
            print("erreur type variable recipe")
            exit()

        self.name = name
        self.cooking_lvl = cooking_lvl
        self.cooking_time = cooking_time
        self.ingredients = []
        self.description = description
        self.recipe_type = recipe_type

    def __str__(self):
        stri = ""
        if self.description == None:
            print("description = None")
            self.description = "No desc"
        for string in self.ingredients:
            stri = string + string
        print("type of recipe", type(self.recipe_type))
        return ("Nom de la recette:" + self.name + "\nlevel :" + str(self.cooking_lvl)
            + "\ningredient : " + stri + "\ndescription : " + self.description
            + "\n recipe type : " + self.recipe_type)


