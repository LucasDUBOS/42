import sys

languages = {
    'Python': 'Guido van Rossum',
    'Ruby': 'Yukihiro Matsumoto',
    'PHP': 'Rasmus Lerdorf',
    }

i = 1
for language in languages:
    print(language,"was created by",languages[language])

