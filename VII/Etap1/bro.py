def browar(miasta):
    sumyOdleglosciP = [0]
    sumyOdleglosciL = [0]
    for i in range(len(miasta)):
        sumyOdleglosciP.append(sumyOdleglosciP[-1] + miasta[i][1])
        sumyOdleglosciL.append(sumyOdleglosciL[-1] + miasta[len(miasta)-1-i][1])
    #print(sumyOdleglosciP)
    sumyOdleglosciL.reverse()
    #print(sumyOdleglosciL)
    sumy = []
    for i in range(len(miasta)):
        sumy.append(0)
    for j in range(len(miasta)):
        for i in range(len(miasta)):
            if i < j:
                odlegloscP = abs(sumyOdleglosciL[j] + sumyOdleglosciP[i])
                #odlegloscP = abs(sumyOdleglosciP[-1] - sumyOdleglosciP[j] + sumyOdleglosciP[i])
                odlegloscL = abs(sumyOdleglosciL[j] - sumyOdleglosciL[i])
            else:
                odlegloscP = abs(sumyOdleglosciP[j] - sumyOdleglosciP[i])
                odlegloscL = abs(sumyOdleglosciP[j] + sumyOdleglosciL[i])
            minimum = min(odlegloscP, sumyOdleglosciP[-1] - odlegloscP)
            #print(j,i,odlegloscP, odlegloscL)
            sumy[j] += minimum * miasta[i][0]
    print(min(sumy))        
        
def beggining():
    ilosc = int(input())
    miasta = []
    for i in range(ilosc):
        wejscie = input().split()
        miasta.append([int(wejscie[0]),int(wejscie[1])])
    browar(miasta)

beggining()
