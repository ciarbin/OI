#include <stdio.h>
#include <list>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
  long value;
  long destination;
};

struct Node {
  list<Edge> neighbours;
  long color;
};

struct Path {
  list<Edge> path;
  bool found = false;
};

Path searchForNode(long searchedNode, long currentNode, vector<Node> &map, long parent) {
  Path out;
  for (Edge neighbour: map[currentNode].neighbours) {
    if(neighbour.destination == searchedNode){
      out.found = true;
      out.path.push_front(neighbour);
      break;
    } else if (neighbour.destination != parent){
      Path test;
      test = searchForNode(searchedNode, neighbour.destination, map, currentNode);
      if (test.found == true) {
        out = test;
        out.path.push_front(neighbour);
        break;
      }
    }
  }
  return out;
}

long long searchForColor(vector<Node> &map, long leftNode, long currentNode, long rightNode, long color) {
  long long minimum = LLONG_MAX;
  for (Edge neigh : map[currentNode].neighbours) {
    if (neigh.destination != leftNode && neigh.destination != rightNode) {
      if (map[neigh.destination].color == color) {
        minimum = std::min(minimum,(long long)neigh.value);
      } else {
        long long tmp;
        tmp = searchForColor(map, currentNode, neigh.destination, currentNode, color);
        if (tmp != LLONG_MAX) {
          tmp = tmp + neigh.value;
        }
        minimum = std::min(minimum, tmp);
      }
    }
  }
  return minimum;
}

void search(vector<Node> &map){
  long start, end, color;
  scanf("%li %li %li", &start, &end, &color);

  Path between;
  long odleglosc = 0;
  bool colorFound = false;
  if (end - 1 != start - 1) {
    between = searchForNode(end - 1, start - 1, map, 0);
  }
  Edge temp;
  temp.destination = start - 1;
  temp.value = 0;
  between.path.push_front(temp);

  for(Edge step: between.path) {
    odleglosc += step.value;
    if (map[step.destination].color == color){
      colorFound = true;
    }
  }

  long long minimum = LLONG_MAX;
  if(colorFound) {
    minimum = odleglosc;
  } else {
    auto poczatek = between.path.begin();
    auto koniec = between.path.begin();
    koniec++;
    for (auto current = between.path.begin(); current != between.path.end(); current++) {
      long long tmp;
      Edge poczatekE = *poczatek, currentE = *current, koniecE = *koniec;
      tmp = searchForColor(map, poczatekE.destination, currentE.destination, koniecE.destination, color);
      minimum = min(minimum, tmp);

      if (current != between.path.begin()) {
        poczatek++;
      }
      if (koniec != between.path.end()) {
        koniec++;
      }
    }
    if (minimum != LLONG_MAX) minimum = minimum * 2 + odleglosc;
  }

  if (minimum == LLONG_MAX) printf("-1\n");
  else printf("%li\n", minimum);
}

int main() {

  long n, r;
  scanf("%li %li", &n, &r);

  vector<Node> map;
  map.resize(n);

  for(long i = 0; i < n; i++) {
    long color;
    scanf("%li", &color);
    map[i].color = color;
  }

  for(long i = 0; i < n - 1; i++) {
    long dest1, dest2, val;
    scanf("%li %li %li", &dest1, &dest2, &val);
    Edge edge1, edge2;
    edge1.destination = dest1 - 1;
    edge2.destination = dest2 - 1;
    edge1.value = val;
    edge2.value = val;
    map[dest2 - 1].neighbours.push_back(edge1);
    map[dest1 - 1].neighbours.push_back(edge2);
  }

  long k;
  scanf("%li", &k);
  for (long i = 0; i < k; i++) {
    search(map);
  }

  return 0;
}
