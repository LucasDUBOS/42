# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filterwords.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 18:18:14 by lucdubos          #+#    #+#              #
#    Updated: 2020/01/13 19:23:00 by lucdubos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def main():
    if len(sys.argv) != 3:
        print("you should try with 2 arguments")
        sys.exit(0)
    if not sys.argv[2].isnumeric():
        print("ERROR")
        sys.exit(0)

    string = str(sys.argv[1])
    n = int(sys.argv[2])
    tab = []
    i = 0;
    j = 0;
    while j < len(string):
        while i < len(string) and string[i].isalpha(): 
            i += 1
        if i - j > n:
            tab.append(string[j:i])
            j = i
        else:
            j += 1
            i = j
    print(tab)


if __name__ == "__main__":
    main()
