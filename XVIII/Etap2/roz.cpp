#include <limits.h>
#include <stdio.h>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int main() {

  long n;
  scanf("%li\n", &n);

  char slowo[n];
  for (long i = 0; i < n; i++) {
    scanf("%c", &slowo[i]);
  }

  map<char,list<long>> wystapienia;

  for(long i = 0; i < n; i++) {
    list<long> temp;
    wystapienia[slowo[i]].push_back(i);
  }

  long wynik = 0;

  for (char c1 = 'a'; c1 <= 'z'; c1++) {
    for (char c2 = c1 + 1; c2 <= 'z'; c2++) {
      auto wyst1 = wystapienia[c1].begin();
      auto wyst2 = wystapienia[c2].begin();
      long wynik1 = 0, wynik2 = 0;
      if (wyst1 != wystapienia[c1].end() && wyst2 != wystapienia[c2].end()){
        //printf("literki: %c %c\n", c1 ,c2);
        long suma1 = 0, suma_pop1 = 0, mini1 = LONG_MAX, suma2 = 0, suma_pop2 = 0, mini2 = LONG_MAX;
        while (wyst1 != wystapienia[c1].end() || wyst2 != wystapienia[c2].end()) {
          //printf("wystapienia: %li %li wystapienia max: %li %li \n", *wyst1, *wyst2, *wystapienia[c1].end(), *wystapienia[c2].end());
          if (wyst1 != wystapienia[c1].end() && *wyst1 < *wyst2 || wyst2 == wystapienia[c2].end()) {
            suma1++;
            suma2--;
            mini2 = min(mini2, suma_pop2);
            suma_pop2 = suma2;
            wyst1++;
          } else {
            suma1--;
            suma2++;
            mini1 = min(mini1, suma_pop1);
            suma_pop1 = suma1;
            wyst2++;
          }
          wynik1 = max(wynik1, suma1 - mini1);
          wynik2 = max(wynik2, suma2 - mini2);
          //printf("wynik1: %li suma1: %li suma_pop1: %li mini: %li\n", wynik1, suma1, suma_pop1, mini1);
        }
        wynik = max(max(wynik, wynik1), wynik2);
        //printf("wynik %li\n", wynik);
      }
    }
  }

  printf("%li\n", wynik);
  return 0;
}
