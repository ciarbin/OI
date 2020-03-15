def krazki(rura, zabawki):
    minima = []
    minimum = rura[0]
    for i in range(len(rura)):
        if rura[i] < minimum:
            minima.append([minimum, i - 1])
            minimum = rura[i]
    minima.append([rura[-1],len(rura) - 1])
    for zabawka in zabawki:
        if len(minima) > 1 and minima [-1][1] > -1:
            while len(minima) > 1 and minima[-1][0] < zabawka:
                del(minima[-1])
            if len(minima) > 2:
                if minima[-1][1] - 1 == minima[-2][1]:
                    del(minima[-1])
                else:
                    minima[-1][1] -= 1
        else:
            if minima[-1][0] < zabawka:
                minima[-1][1] = -1
            else:
                minima[-1][1] = 0
                minima[-1][0] = 0
    print(minima[-1][1] + 1)

def krazki2(rura, zabawki):
    minima = []
    minimum = rura[0]
    for i in range(len(rura)):
        if rura[i] <= minimum:
            minimum = rura[i]
        minima.append(minimum)
    zmiesciloOstatnie = False
    for zabawka in zabawki:
        if len(minima) > 0:
            while(len(minima) > 0 and minima[-1] < zabawka):
                del(minima[-1])
            if len(minima) > 0:
                del(minima[-1])
                if len(minima) == 0:
                    zmiesciloOstatnie = True
        else:
            zmiesciloOstatnie = False
    if len(minima) > 0 or zmiesciloOstatnie == True:
        print(len(minima) + 1)
    else:
        print(0)
                

def beggining():
    nic = input()
    ruraRaw = input()
    zabawkiRaw = input()
    rura = []
    zabawki = []
    ruraRaw = ruraRaw.split()
    zabawkiRaw = zabawkiRaw.split()
    for wartosc in ruraRaw:
        rura.append(int(wartosc))
    for wartosc in zabawkiRaw:
        zabawki.append(int(wartosc))
    krazki2(rura,zabawki)
    
beggining()
