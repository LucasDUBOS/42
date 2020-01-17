# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 10:22:17 by lucdubos          #+#    #+#              #
#    Updated: 2020/01/14 14:41:33 by lucdubos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


from book import book
from recipe import Recipe

tarte = Recipe("tourte", 1, 15, ['lait','chocolat','pinguin'],'lunch','description de la tarte')

print(type(tarte))

to_print = str(tarte)
print(to_print)


livre = book("titre du livre", tarte)
print("BOOK :")

print(livre.recipes_list['lunch'][0].name)



#livre = book("nom du livre")
#print(livre.last_update)

#dict = {'starter': 
