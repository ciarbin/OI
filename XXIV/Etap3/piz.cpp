#include <stdio.h>
#include <list>

using namespace std;


struct Edge {
  long val;
  long destination;
};

struct Node{
  Edge parent;
  list<Edge> childs;
  long wGore;
  long wDol;
  long downChild;
};

void fillTree(long node, long parent, *list<Edge> tTemp, *Node t[], long wGore) {
  for(Edge neigh : tTemp[node]) {
    if (neigh.destination == parent) {
      t[node].parent = neigh;
    } else {
      t[node].childs.push_front(neigh);
      fillTree(neigh.destination, node, tTemp, *t, wGore + neigh.val);
    }
  }
  t[node].wGore = wGore;
}

int main() {
  long n,k;
  scanf("%li %li", &n, &k);

  list<Edge> tTemp[n] = {};

  for(long i = 0; i < n - 1; i++) {
    long dom1, dom2, waga;
    scanf("%li %li %li", &dom1, &dom2, &waga);
    Edge temp1;
    Edge temp2;
    temp1.destination = dom2 - 1;
    temp1.val = waga;
    t[dom1 - 1].push_front(temp1);
    temp2.destination = dom1 - 1;
    temp2.val = waga;
    t[dom2 - 1].push_front(temp2);
  }

  Node t[n];

  for
  printf("\n\n");

  for(long i = 0; i < n; i++) {
    printf("Wierzcholek: %li ", i);
    for(Edge val : t[i]) {
      printf("Do: %li Waga: %li \n", val.destination, val.val);
    }
  }
}
