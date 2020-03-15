#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int ilosc_domow = 0, wynik = 0;

  scanf("%d", &ilosc_domow);

  stack<int> aktywnePlakaty;

  for(int i = 0; i < ilosc_domow; i++) {
    int budynek, nic;
    scanf("%d %d", &nic, &budynek);
    while(!aktywnePlakaty.empty() && aktywnePlakaty.top() > budynek) {
      aktywnePlakaty.pop();
    }
    if(aktywnePlakaty.empty() || budynek != aktywnePlakaty.top()) {
      wynik++;
      aktywnePlakaty.push(budynek);
    }
  }

  printf("%d", wynik);
}
