#include <stdio.h>

using namespace std;

void wypisz(int wiersz, int kolumna, char kierunek, bool czyObrocone) {
  int wiersz2;
  int kolumna2;
  if (kierunek == 'g') {
    wiersz2 = wiersz - 1;
    kolumna2 = kolumna;
  } else if (kierunek == 'd') {
    wiersz2 = wiersz + 1;
    kolumna2 = kolumna;
  } else if (kierunek == 'p') {
    wiersz2 = wiersz;
    kolumna2 = kolumna + 1;
  } else if (kierunek == 'l') {
    wiersz2 = wiersz;
    kolumna2 = kolumna - 1;
  }
  if (czyObrocone) {
    int temp = wiersz;
    wiersz = kolumna;
    kolumna = temp;
    temp = wiersz2;
    wiersz2 = kolumna2;
    kolumna2 = temp;
  }
  printf("%d %d %d %d \n", wiersz, kolumna, wiersz2, kolumna2);
}

int main() {
  bool czyObrocone = false;
  int n, m;
  long k;
  scanf ("%d %d %ld",&n, &m, &k);

  if(k < n + m - 2 || k > n * m - 1 || (n % 2 == 0 && m % 2 == 0 && k < n + m - 1 )) {

    printf("NIE \n");

  } else if (n == 1 || m == 1){

    printf("TAK \n");

    if (m == 1) {
      int tmp = n;
      n = m;
      m = tmp;
      czyObrocone = true;
    }

    for (int i = 1; i < m; i++) {
      wypisz(1, i + 1, 'l', czyObrocone);
    }

  } else if ((n == 2 || m == 2) && k != n + m - 2){

    printf("TAK \n");

    if (m == 2) {
      int tmp = n;
      n = m;
      m = tmp;
      czyObrocone = true;
    }

    for (int i = 1; i < m; i++) {
      wypisz(1, i + 1, 'l', czyObrocone);
    }

    wypisz(2, 1, 'g', czyObrocone);

    for (int i = 1; i < m; i++) {
      if (i <= k - m - 1) wypisz(2, i + 1, 'l', czyObrocone);
      else wypisz(2, i + 1, 'g', czyObrocone);
    }

  } else {

    printf("TAK \n");

    long ilePonadGdyParzyste = -1;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k - m > m + n - 3) {
        ilePonadGdyParzyste = m;
        k -= m;
      } else {
        ilePonadGdyParzyste = 0;
        k--;
      }
      n--;
    }
    long iloscPonad = k - (n + m - 2);

    if(n % 2 != 1 && m % 2 == 1) {
      int temp = n;
      n = m;
      m = temp;
      czyObrocone = true;
    }

    int rzadWeza = (iloscPonad - 1) / (m - 1);
    int rzadSrodkowy = (n - 1) / 2;

    //printf("rzadWeza: %lu\n", rzadWeza);
    //printf("iloscPonad: %lu\n", iloscPonad);

    int kolumnaWeza;
    if (rzadWeza % 2 == 1) {
      kolumnaWeza = (iloscPonad - 1) % (m - 1);
    } else {
      kolumnaWeza = ((m - 1) - (iloscPonad) % (m - 1)) % (m - 1);
    }

    if (rzadWeza == n - 1) {
      rzadWeza--;
    }

    //printf("kolumnaWeza: %lu\n", kolumnaWeza);

    if (rzadSrodkowy <= rzadWeza) {
      rzadSrodkowy = rzadWeza + 1;
    }

    if (k == n + m - 2){
      rzadWeza = -1;
    }
    if (rzadSrodkowy == n - 1 && k != n * m - 1) {
      k -= 1;
    }

    for(int rzad = 0; rzad < n; rzad++) {
      for(int kolumna = 0; kolumna < m; kolumna++) {
        if (rzad > rzadWeza && rzad < rzadSrodkowy) {
          wypisz(rzad + 1, kolumna + 1, 'd', czyObrocone);
        } else if (rzad > rzadSrodkowy) {
          wypisz(rzad + 1, kolumna + 1, 'g', czyObrocone);
        } else if (rzad == rzadSrodkowy) {
          if (kolumna != 0) wypisz(rzad + 1, kolumna + 1, 'l', czyObrocone);
        } else if (rzad == 0 && rzadWeza != -1 && kolumna == m - 2) {
          wypisz(rzad + 1, kolumna + 1, 'p', czyObrocone);
        } else if (rzad < rzadWeza) {
          if (kolumna == m - 1) wypisz(rzad + 1, kolumna + 1, 'd', czyObrocone);
          else if (rzad % 2 == 0){
            if (kolumna == m - 2) {
              wypisz(rzad + 1, kolumna + 1, 'g', czyObrocone);
            } else {
              wypisz(rzad + 1, kolumna + 1, 'p', czyObrocone);
            }
          } else {
            if (kolumna == 0) {
              wypisz(rzad + 1, kolumna + 1, 'g', czyObrocone);
            } else {
              wypisz(rzad + 1, kolumna + 1, 'l', czyObrocone);
            }
          }

        } else if(rzad == rzadWeza) {
          if (kolumna == m - 1) wypisz(rzad + 1, kolumna + 1, 'd', czyObrocone);
          else if (rzadWeza % 2 == 0) {
            if (kolumna == m - 2) {
              wypisz(rzad + 1, kolumna + 1, 'g', czyObrocone);
            } else if (kolumna >= kolumnaWeza) {
              wypisz(rzad + 1, kolumna + 1, 'p', czyObrocone);
            } else {
              wypisz(rzad + 1, kolumna + 1, 'd', czyObrocone);
            }
          } else {
            if (kolumna == 0) {
              wypisz(rzad + 1, kolumna + 1, 'g', czyObrocone);
            } else if (kolumna <= kolumnaWeza) {
              wypisz(rzad + 1, kolumna + 1, 'l', czyObrocone);
            } else {
              wypisz(rzad + 1, kolumna + 1, 'd', czyObrocone);
            }
          }
        }
      }
    }
    if (ilePonadGdyParzyste > -1) {
      for(int kolumna = 0; kolumna < m; kolumna++) {
        if (kolumna == 0) wypisz(n + 1, kolumna + 1, 'g', czyObrocone);
        else if(kolumna < ilePonadGdyParzyste) wypisz(n + 1, kolumna + 1, 'l', czyObrocone);
        else wypisz(n + 1, kolumna + 1, 'g', czyObrocone);
      }
    }
  }
  return 0;
}
