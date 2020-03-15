#include <stdio.h>
#include <algorithm>

using namespace std;

struct Skok {
    long lewo = 0;
    long prawo = 0;

};

void skacz(long cel, long poczatek, long koniec) {
  if (cel >= poczatek) {
    printf("%li ", cel + koniec - poczatek + 1);
  } else {
    printf("%li ", cel);
  }
}

int main() {
    long n = 0, s = 0;
    scanf("%ld %ld", &n, &s);

    long iloscWPrawo = 0, iloscWLewo = 0, iloscBezRoznicy = 0;

    Skok skoki[n - 1];

    unsigned long long koszt = 0;
    pair<long, long> minimalnyNieOptymalnyWLewo = make_pair(0, 10000000);   //first - ktory skok
    pair<long, long> minimalnyNieOptymalnyWPrawo = make_pair(0, 10000000);  //second - wartosc stracona
    bool czyMuszeWPrawo = false, czyMuszeWLewo = false;


    for (long i = 0; i < n - 1; i++) {
        long l, p;
        scanf("%li %li", &l, &p);

        skoki[i].lewo = l;
        skoki[i].prawo = p;

        koszt += min(l, p);

        if(l < p) {
            iloscWLewo++;
            if(czyMuszeWPrawo == false && p - l < minimalnyNieOptymalnyWPrawo.second) {
                minimalnyNieOptymalnyWPrawo = make_pair(i, p - l);
            }
        } else if(p < l) {
            iloscWPrawo++;
            if(czyMuszeWLewo == false && l - p < minimalnyNieOptymalnyWLewo.second) {
                minimalnyNieOptymalnyWLewo = make_pair(i, l - p);
            }
        } else {
            iloscBezRoznicy++;
        }

        if(i == s - 1 && iloscBezRoznicy == 0 && iloscWPrawo == 0) {
          czyMuszeWPrawo = true;
        }
        if(i == n - s && iloscBezRoznicy == 0 && iloscWLewo == 0) {
          czyMuszeWLewo = true;
        }
    }

    if(czyMuszeWLewo) {
      koszt += minimalnyNieOptymalnyWLewo.second;
    } else if(czyMuszeWPrawo) {
      koszt += minimalnyNieOptymalnyWPrawo.second;
    }

    printf("%llu \n", koszt);

    printf("%li ", s);
    long srodek = iloscWLewo, pozycja = s, max = n - 1, poczatek = s, koniec = s;
    for (int i = 0; i < n - 1; i++) {
      if (czyMuszeWLewo && i <= minimalnyNieOptymalnyWLewo.first) {
        if (i < minimalnyNieOptymalnyWLewo.first) {
          printf("%li ", ++pozycja);
          koniec++;
        } else {
          max = n - minimalnyNieOptymalnyWLewo.first - 1;
          skacz(iloscWLewo + 1, poczatek, koniec);
          pozycja = iloscWLewo + 1;
          srodek++;
        }
        iloscWPrawo--;
      } else if (czyMuszeWPrawo && i <= minimalnyNieOptymalnyWPrawo.first) {
        if (i < minimalnyNieOptymalnyWPrawo.first) {
          printf("%li ", --pozycja);
          poczatek--;
          srodek--;
        } else {
          max = n - minimalnyNieOptymalnyWPrawo.first - 1;
          skacz(max - iloscWPrawo, poczatek, koniec);
          pozycja = max - iloscWPrawo;
          srodek--;
        }
        iloscWLewo--;
      } else {
        if(skoki[i].lewo < skoki[i].prawo) {
          if (iloscWLewo >= pozycja) {
            skacz(--pozycja, poczatek--, koniec);
            max--;
            srodek--;
          } else {
            skacz(iloscWLewo, poczatek, koniec);
            pozycja = iloscWLewo;
          }
          iloscWLewo--;
        } else if (skoki[i].lewo > skoki[i].prawo){
          if(max - iloscWPrawo + 1 <= pozycja) {
            skacz(pozycja, poczatek, koniec++);
            max--;
          } else {
            skacz(max - iloscWPrawo + 1, poczatek, koniec);
            pozycja = max - iloscWPrawo + 1;
          }
          iloscWPrawo--;
        } else {
          skacz(srodek + iloscBezRoznicy, poczatek, koniec);
          pozycja = srodek + iloscBezRoznicy;
          iloscBezRoznicy--;
        }
      }
    }

    return 0;
}
