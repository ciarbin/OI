//#include "cyklib.hpp"
#include <stdio.h>

using namespace std;

struct Zadanie {
  long n = 1231;
  long long lista[1231];
  long x0 = 120;
  long zapytania = -1;

  void init() {
    for(int i = 0; i < n; i++) {
      lista[i] = i;
    }
    circular_shift(x0);
    print();
  }

  long long circular_shift(long x) {
    for(int i = 0; i < x; i++) {
      long long val1 = lista[0];
      for(int j = 1; j < n; j++) {
        lista[j-1] = lista[j];
      }
      lista[n - 1] = val1;
    }
    zapytania++;
    return(lista[0]);
  }

  void print(){
    printf("\n");
    for (long i = 1; i < n; i++) {
      printf("%li ", lista[i]);
    }
    printf("\n");
  }

};

int main() {
  Zadanie trening;
  trening.init();
  long dist = 1, greaterThen = 1, lesserThen = 1;
  long long start, lastVal, newVal, krok;
  start = trening.circular_shift(0);
  lastVal = start;
  newVal = trening.circular_shift(1);
  while( !(lastVal < start && newVal > start) &&
      !(lastVal < start && newVal < lastVal) &&
      !(lastVal > newVal && newVal > start) &&
      !(newVal == start) && !(newVal == lastVal)) {
    dist *= 2;
    lastVal = newVal;
    newVal = trening.circular_shift(dist);
    greaterThen = lesserThen;
    lesserThen += dist;
    printf("start:%li ", start);
    printf("lastVal:%lli newVal:%lli ", lastVal, newVal);
    printf("greaterThen:%li lesserThen:%li\n", greaterThen, lesserThen);
  }

  printf("END! greaterThen:%li lesserThen:%li dist:%li\n", greaterThen, lesserThen, dist);

  if (newVal == lastVal) {
    lesserThen = dist;
  } else if (newVal == start) {
    ;
  } else {
    while (newVal != start) {
      printf("start:%li ", start);
      printf("lastVal:%lli newVal:%lli ", lastVal, newVal);
      printf("greaterThen:%li lesserThen:%li\n", greaterThen, lesserThen);
      start = newVal;
      krok = trening.circular_shift(greaterThen);
      dist = dist / 2;
      lesserThen -= dist;
      newVal = trening.circular_shift(dist);
      while (((krok < start && newVal < start && newVal > krok) ||
              (krok > start && (newVal > krok || newVal < start))) &&
            start != krok) {
        printf("HA!");
        greaterThen = lesserThen;
        dist = dist / 2;
        lesserThen += dist;
        newVal = trening.circular_shift(dist);
      }
      //greaterThen = lesserThen;
    }
  }
  printf("\nWynik: %li iloscZapytan: %li", lesserThen, trening.zapytania);
}
