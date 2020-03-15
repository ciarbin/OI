import bisect

def plakaty():
    obecnePlakaty = []
    wynik = 0
    ilosc = int(input())
    for i in range(ilosc):
        budynek = int(input().split()[1])
        obecnePlakaty = obecnePlakaty[:bisect.bisect_right(obecnePlakaty,budynek)]
        if len(obecnePlakaty) == 0 or budynek != obecnePlakaty[-1]:
            wynik += 1
            obecnePlakaty.append(budynek)
    print(wynik)
                
plakaty()
