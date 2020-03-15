// Example program
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct Best{
  unsigned long depth;
  unsigned long nodes;
};

Best check(unsigned long parent, unsigned long node, vector<vector<unsigned long>> t) {
  Best own;
  if (t[node].size() == 1) {
    own.depth = 0;
    own.nodes = 1;
  } else {
    own.depth = 1;
    own.nodes = 0;
    for (unsigned long neigh : t[node]) {
      if (neigh != parent) {
        Best temp;
        temp = check(node, neigh, t);
        if ((temp.nodes + t[node].size() - 2) / (temp.depth + 1) > own.nodes / own.depth) {
          own.nodes = temp.nodes + t[node].size() - 2;
          own.depth = temp.depth + 1;
        }
      }
    }
  }
  return own;
}

int main()
{
  unsigned long n;
  scanf("%lu", &n);

  vector<vector<unsigned long>> t;
  for (unsigned long i = 0; i < n; i++) {
    vector<unsigned long> temp;
    t.push_back(temp);
  }
  for (unsigned long i = 0; i < n-1; i++) {
    unsigned long temp1, temp2;
    scanf("%lu %lu", &temp1, &temp2);
    t[temp1-1].push_back(temp2-1);
    t[temp2-1].push_back(temp1-1);
  }

  Best wynik;
  wynik = check(0, 0, t);
  unsigned long wynikVal = wynik.nodes / wynik.depth + 1;
  //printf("%lu %lu", wynik.nodes, wynik.depth);
  printf("%lu", wynikVal);
  //printf("Wynik = %lu \n\n", wynikVal);

  // for (unsigned long i = 0; i < n; i++) {
  //   printf("Wierzcholek %lu:\n", i);
  //   for (unsigned long val : t[i]) {
  //     printf("%lu ", val);
  //   }
  //   printf("\n\n");
  // }
}
