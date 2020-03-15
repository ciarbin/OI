#include <list>
#include <math.h>
#include <stdio.h>

using namespace std;

int NWD(long a, long b)
{
  while(b != 0) {
    long pom = b;
    b = a % b;
    a = pom;
  }
  return a;
}

void nww() {
  long long liczba;
  scanf("%lli", &liczba);

  long start = 1, i = 0;
  long long nww = 1;
  long granica = sqrt(liczba) + 1;

  for (i = 2; i <= granica; i++){
    long mod = liczba % i;
    if (mod == 0) {
      if (start == 0) {
        start = i;
        nww = i;
      } else {
        nww = (nww * i) / NWD(nww,i);
      }

      if (nww == liczba) {
        break;
      }
    } else {
      start = 0;
      nww = 1;
    }
  }
  if (start != i && start != 0) {
    printf("%li %li\n", start, i);
  } else {
    printf("NIE\n");
  }
}

int main() {
  int zapytania;
  scanf("%i", &zapytania);
  for (int i = 0; i < zapytania; i++) {
    nww();
  }
  return 0;
}
