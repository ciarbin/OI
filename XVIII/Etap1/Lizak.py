import copy

def lizak(cukierek, kieszonkowe):
    for granica in kieszonkowe:
        poczatek = 0
        koniec = 0
        suma = 0
        while koniec != len(cukierek) and suma != granica:
            if suma > granica:
                if cukierek[poczatek] == 'W':
                    suma -= 1
                else:
                    suma -= 2
                poczatek += 1
            else:
                if cukierek[koniec] == 'W':
                    suma += 1
                else:
                    suma += 2
                koniec += 1
        if suma == granica:
            print([poczatek + 1, koniec])
        else:
            print("NIE")


def lizak2(cukierek, kieszonkowe):
    translate = {"T":"2","W":"1"}
    wartosci = ""
    for letter in cukierek:
        wartosci += translate[letter]

    przedzialy = []
    for i in range(2 * len(cukierek)):
        przedzialy.append([0,0])
    maxsuma1 = 0
    for i in range(len(wartosci)):
        maxsuma1 += int(wartosci[i])

    L = 0
    while L < len(wartosci) and wartosci[L] != "1":
        L += 1
    R = 0
    while R < len(wartosci) and wartosci[len(wartosci) - R - 1] != "1":
        R += 1

    if L < R :
        maxsuma2 = maxsuma1 - L * 2 - 1
        przedzial2 = [L ,len(wartosci) - 1]
    elif R != len(wartosci):
        maxsuma2 = maxsuma1 - R * 2 - 1
        przedzial2 = [0,len(wartosci) - R - 2]
    przedzial1 = [0,len(wartosci) - 1]

    przedzialy[maxsuma1 - 1] = copy.deepcopy(przedzial1)
    przedzialy[maxsuma2 - 1] = copy.deepcopy(przedzial2)

    while maxsuma1 > 2:
        if wartosci[przedzial1[0]] == "2":
            przedzial1[0] += 1
        elif wartosci[przedzial1[1]] == "2":
            przedzial1[1] -= 1
        else:
            przedzial1[0] += 1
            przedzial1[1] -= 1
        maxsuma1 -=2
        przedzialy[maxsuma1 - 1] = copy.deepcopy(przedzial1)
    while maxsuma2 > 2:
        if wartosci[przedzial2[0]] == "2":
            przedzial2[0] += 1
        elif wartosci[przedzial2[1]] == "2":
            przedzial2[1] -= 1
        else:
            przedzial2[0] += 1
            przedzial2[1] -= 1
        maxsuma2 -=2
        przedzialy[maxsuma2 - 1] = copy.deepcopy(przedzial2)

    for sprawdzenie in kieszonkowe:
        if sprawdzenie <= len(wartosci) * 2:
            if przedzialy[sprawdzenie - 1] != [0,0]:
                print([przedzialy[sprawdzenie - 1][0] + 1, przedzialy[sprawdzenie - 1][1] + 1])
            else:
                print("NIE")
        else:
            print("NIE")
        
    
