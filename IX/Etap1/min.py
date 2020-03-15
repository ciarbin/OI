def minusy(kolejnosc):
    wynik = ""
    otwarte = False
    for znak in kolejnosc:
        if (znak == "-" and otwarte == False) or (znak == "+" and otwarte == True):
            wynik += "-"
        elif znak == "-" and otwarte == True:
            wynik += ")-"
            otwarte = False
        elif znak == "+" and otwarte == False:
            wynik += "(-"
            otwarte = True
    if otwarte == True:
        wynik += ")"
    return wynik

ilosc = input()
wnetrze = ""
for i in range(int(ilosc) - 1):
    wnetrze += input()
print(minusy(wnetrze))
