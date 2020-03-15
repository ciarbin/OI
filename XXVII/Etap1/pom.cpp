#include <string>
#include <iostream>

using namespace std;

void pom(){
  long k;
  bool niemozliwe = false;
  string gracz1, gracz2;
  cin >> gracz1 >> gracz2 >> k;
  string wynik = string(gracz1.length(), '-');
  for (long i = 0; i < gracz1.length(); i++) {
    if (gracz1.length() - i <= k) { //Tyle trzeba zmienic co zostalo miejsca
      long j = i;
      while (j < gracz1.length() - 1 && gracz1[j] != gracz2[j] && k > 1) {
        wynik[j] = gracz2[j];
        k--;
        j++;
      }
      wynik[j] = gracz1[j];
      for (j; j >= 0; j--) {
        if (gracz1[j] != wynik[j]) {
          k++;
        }
        if (gracz2[j] != '0' && !(gracz1[j] == '0' && gracz2[j] == '1') && gracz1.length() - j >= k) {
          break;
        }
      }
      if (j == -1) {
        niemozliwe = true;
        break;
      }
      if (gracz1[j] != gracz2[j] - 1 || gracz1.length() - j > k) {
        wynik[j] = gracz2[j] - 1;
        if (gracz1[j] != gracz2[j] - 1) {
          k--;
        }
      } else {
        wynik[j] = gracz2[j] - 2;
        k--;
      }
      j++;
      while (j < gracz1.length()) {
        if (gracz1.length() - j <= k && k > 0) {
          if (gracz1[j] == '9') {
            wynik[j] = '8';
          } else {
            wynik[j] = '9';
          }
          k--;
        } else if (k > 0 && gracz1[j] != '9') {
          wynik[j] = '9';
          k--;
        } else {
          wynik[j] = gracz1[j];
        }
        j++;
      }
      break;
    } else if(gracz1[i] != gracz2[i] & k != 0) { //zmiana
      if (k == 1) { ///////////////////////////////////Ostatnia zmiana
        bool czyWszystkieMniejsze = true,czyWszyskieRowne = true;
        for (long j = i + 1; j < gracz1.length(); j++){
          if (gracz1[j] > gracz2[j] && czyWszyskieRowne == true) {
            czyWszystkieMniejsze = false;
          } if (gracz1[j] != gracz2[j]) {
            czyWszyskieRowne = false;
          }
          wynik[j] = gracz1[j];
        }
        if (i + 1 == gracz1.length() && gracz1[i] - 1 != gracz2[i]) {
          wynik[i] = gracz2[i] - 1;
          k--;
          break;
        } else if (czyWszystkieMniejsze && !czyWszyskieRowne) {
          wynik[i] = gracz2[i];
          k--;
          break;
        } else {
          long j;
          wynik[i] = gracz1[i];
          for (j = i; j >= 0; j--) {
            if(gracz1[j] != wynik[j]) {
              k++;
              wynik[j] = gracz1[j];
            }
            if(gracz2[j] != '0') {
              break;
            }
          }
          if (j >= 0) {
            if (gracz1[j] != gracz2[j] - 1 ) {
              k--;
            }
            wynik[j] = gracz2[j] - 1;
            j++;
            while (j < gracz1.length()) {
              if (gracz1.length() - j <= k && k > 0) {
                if (gracz1[j] == '9') {
                  wynik[j] = '8';
                } else {
                  wynik[j] = '9';
                }
                k--;
              } else if (k > 0 && gracz1[j] != '9') {
                wynik[j] = '9';
                k--;
              } else {
                wynik[j] = gracz1[j];
              }
              j++;
            }
            break;
          } else {
            niemozliwe = true;
            break;
          }
        }
      } else if (k > 1) {
        wynik[i] = gracz2[i];
        k--;
      }
    } else {
      wynik[i] = gracz1[i];
    }
  }
  if (niemozliwe) {
    cout << "-1\n";
  } else {
    cout << wynik << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  unsigned int t;

  cin >> t;

  for(unsigned int i = 0; i < t; i++) {
    pom();
  }
  return 0;
}
