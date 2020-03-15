//#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int n,m;
  //cin >> n >> m;
  scanf ("%d %d",&n, &m);

  int rura[n];
  int minimum;
  for(int i = 0; i < n; i++) {
    int zmienna;
    scanf("%d", &zmienna);
    //cin >> zmienna;
    if(i == 0){
      minimum = zmienna;
    }
    if(zmienna < minimum) {
      minimum = zmienna;
    }
    rura[i] = minimum;
  }

  int zabawka;
  bool zmiesciloOstatnie = false;
  int poziom = n;
  for(int i = 0; i < m; i++) {
    if(poziom > 0) {
      //cin >> zabawka;
      scanf("%d", &zabawka);
      while(poziom > 0 and rura[poziom - 1] < zabawka) {
        poziom--;
      }
      if(poziom > 0){
        poziom--;
        if(poziom == 0){
          zmiesciloOstatnie = true;
        }
      }
    } else {
      zmiesciloOstatnie = false;
    }
  }

  if(poziom > 0){
    //cout << poziom + 1;
    printf("%d", poziom + 1);
  } else if(zmiesciloOstatnie == true) {
    //cout << 1;
    printf("%d", 1);
  } else {
    //cout << 0;
    printf("%d", 0);
  }

  return 0;
}
