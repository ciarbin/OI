#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>

using namespace std;

struct Edge {
  unsigned long dest;
  unsigned long val;
};

struct Node{
  Edge parent;
  list<Edge> childs;
  unsigned long wGore;
  unsigned long wDol;
  unsigned long childDol;
};

unsigned long wypelnij(vector<vector<Edge>> &tempT, vector<Node> &t, unsigned long node, unsigned long parent, unsigned long wGore) {
  unsigned long bestWDol = 0;
  t[node].childDol = 0;
  for (unsigned long i = 0; i < tempT[node].size(); i++) {
    if (tempT[node][i].dest != parent) {
      t[node].childs.push_back(tempT[node][i]);
      unsigned long tempDol;
      tempDol = wypelnij(tempT, t, tempT[node][i].dest, node, wGore + tempT[node][i].val) + tempT[node][i].val;
      if (tempDol > bestWDol) {
        bestWDol = tempDol;
        t[node].childDol = tempT[node][i].dest;
      }
    } else {
      t[node].parent = tempT[node][i];
    }
  }
  t[node].wGore = wGore - t[node].parent.val;
  t[node].wDol = bestWDol + t[node].parent.val;
  return bestWDol;
}

void dodajInteresujace(set<pair<long long, unsigned long>, less<pair<long long, unsigned long>>> &interesujaceWierzcholki, unsigned long node, vector<Node> &t) {
  for (Edge temp : t[node].childs) {
    if (temp.dest != t[node].childDol) {
      interesujaceWierzcholki.insert(make_pair((long long)t[temp.dest].wGore - (long long)t[temp.dest].wDol, temp.dest));
    }
  }
  if(t[node].childDol != 0) {
    dodajInteresujace(interesujaceWierzcholki, t[node].childDol, t);
  }
}

int main() {
  unsigned long n, k;
  scanf("%lu %lu", &n, &k);

  vector<vector<Edge>> tempT;
  tempT.resize(n);

  unsigned long long wynik = 0;

  for (unsigned long i = 0; i < n - 1; i++) {
    unsigned long neigh1, neigh2, val;
    Edge temp1, temp2;
    scanf("%lu %lu %lu", &neigh1, &neigh2, &val);
    wynik += (unsigned long long)2 * val;
    temp1.val = val;
    temp2.val = val;
    temp1.dest = neigh2 - 1;
    temp2.dest = neigh1 - 1;
    tempT[neigh1 - 1].push_back(temp1);
    tempT[neigh2 - 1].push_back(temp2);
  }

  vector<Node> t;
  t.resize(n);
  wypelnij(tempT, t, 0, 0, 0);

  set<pair<long long int, unsigned long>, less<pair<long long, unsigned long>>> interesujaceWierzcholki;
  interesujaceWierzcholki.insert(make_pair((-(long long int)t[0].wDol), 0));

  for (unsigned long i = 0; i < k; i++) {
    pair<long long, unsigned long> temp = *(interesujaceWierzcholki.begin());
    if (temp.first < 0) {
      wynik += temp.first;
      dodajInteresujace(interesujaceWierzcholki, temp.second, t);
      interesujaceWierzcholki.erase(interesujaceWierzcholki.find(temp));
    } else {
      break;
    }
  }

  printf("%llu\n", wynik);
}
