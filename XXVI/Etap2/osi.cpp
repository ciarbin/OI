#include <stdio.h>
#include <list>
#include <vector>

using namespace std;

struct Edge {
  long destination;
  bool direction = false;
};

struct Node {
  list<Edge> neighbours;
  bool visited = false;
  bool inProgress = false;
};

long DFS(long currentNode, long parent, long &cyclesCount, vector<Node> &map) {
  long retVal = 0;
  map[currentNode].inProgress = true;
  map[currentNode].visited = true;
  for (auto neigh = map[currentNode].neighbours.begin(); neigh != map[currentNode].neighbours.end(); neigh++) {
    if (neigh->destination == parent) {
      parent = -1;
    } else if (map[neigh->destination].visited && map[neigh->destination].inProgress) {
      retVal++;
      neigh->direction = true;
    } else if (map[neigh->destination].visited && !map[neigh->destination].inProgress) {
      retVal--;
    } else {
      long tmp;
      tmp = DFS(neigh->destination, currentNode, cyclesCount, map);
      retVal += tmp;
      neigh->direction = true;
    }
  }
  if (retVal == 0) {
    cyclesCount++;
  }
  map[currentNode].inProgress = false;
  return retVal;
}

void test(long &lol) {
  lol++;
}

int main() {
  long n, m;
  scanf("%li %li", &n, &m);

  vector<Node> map;
  map.resize(n);

  list<pair<long, long>> kolejnosc;

  for(long i = 0; i < m; i++) {
    long node1, node2;
    scanf("%li %li", &node1, &node2);
    Edge tmp1, tmp2;
    tmp1.destination = node2 - 1;
    tmp2.destination = node1 - 1;
    map[node1 - 1].neighbours.push_back(tmp1);
    map[node2 - 1].neighbours.push_back(tmp2);
    pair<long, long> tmp = make_pair(node1 - 1, node2 - 1);
    kolejnosc.push_back(tmp);
  }

  long cyclesCount = 0;
  for(long i = 0; i < n; i++) {
    if(map[i].visited == false) {
      DFS(i, -1, cyclesCount, map);
    }
  }
  printf("%li\n", cyclesCount);

  for(pair<long, long> edge : kolejnosc) {
    long times = 0;
    for(auto tmp = map[edge.first].neighbours.begin(); tmp != map[edge.first].neighbours.end(); tmp++) {
      if (tmp->destination == edge.second) {
        if (tmp->direction) {
          printf(">");
        } else {
          printf("<");
        }
        for (auto tmp2 = map[tmp->destination].neighbours.begin(); tmp2 != map[tmp->destination].neighbours.end(); tmp2++){
          if (tmp2->destination == edge.first && tmp2->direction != tmp->direction) {
            map[tmp->destination].neighbours.erase(tmp2);
            break;
          }
        }
        map[edge.first].neighbours.erase(tmp);
        break;
      }
    }
  }
  printf("\n");

  return 0;
}
