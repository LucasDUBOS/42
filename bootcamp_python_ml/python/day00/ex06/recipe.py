

cookbook = {
    'sandwich': {'ingredients': ['ham', 'bread', 'cheese', 'tomatoes'], 'meal':'lunch', 'prep_time': '10 minutes'},
     'cake': {'ingredients': {'flour','sugar', 'eggs'}, 'meal':'dessert', 'prep_time': '60 minutes'},
   'salad': {'ingredients': {'avocado', 'arugula', 'tomatoes', 'spinach'}, 'meal':'lunch', 'prep_time': '15 minutes'},
    }

def print_recipe(recipe):
       print(cookbook[recipe])

def delete_recipe(recipe):
    del cookbook['recipe']
"""
def add_recipe(recipe):
    ingredients = '0'
    cookbook[recipe] = {'ingredients', 'meal', 'prep_time'}
    while ingredients != '1':
        ingredients += input("add ingredient else type 1")
        cookbook[recipe]['ingredients'] = ingredients
"""



while 1:
    choice = input("\n\nPlease select an option by typing the corresponding number:\n1: Add a recipe\n2: Delete a recipe\n3: Print a recipe\n4: Print the cookbook\n5: Quit\n")
    if choice == '4':
        print(cookbook)
    elif choice == '3':
        print_recipe(input("Please enter the recipe's name to get its details:\n"))
    elif choice == '2':
        delete_recipe(input("Please enter the recipe's name to delete:\n"))
    elif choice == '1':
        add_recipe(input("Please enter the recipe's name to add:\n"))
    elif choice == '5':
        print ("\nCookbook closed")
        exit()
    else:
        print("\n\n\nThis option does not exist, please type the corresponding number. To exit, enter 5.\n\n\n")


