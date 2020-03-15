#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Node {
  bool visited = false;
  set<long> neighbours;
};

void count_options(Node graph[], long long ks[], long long* num_of_options, long n, long m, long z) {
  long val[n] = {0};
  long bezkrawedzi[] = {0, 0};
  for (int i = 0; i < n; i++) {
    set<long> odwiedzeniSasiedzi;
    for (set<long>::iterator neighbour = graph[i].neighbours.begin(); neighbour != graph[i].neighbours.end(); ++neighbour) {
      if (graph[*neighbour].visited) {
        for (set<long>::iterator neighbour2 = odwiedzeniSasiedzi.begin(); neighbour2 != odwiedzeniSasiedzi.end(); ++neighbour2) {
          if (graph[*neighbour].neighbours.find(*neighbour2) == graph[*neighbour].neighbours.end()) {
            bezkrawedzi[0] = *neighbour;
            bezkrawedzi[1] = *neighbour2;
            goto exit;
          }
        }
        odwiedzeniSasiedzi.insert(*neighbour);
        val[i]++;
      }
    }
    graph[i].visited = true;
  }{
  long long mod = 1000000000 + 7;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < z; j++) {
      *(num_of_options + j) = (*(num_of_options + j) * (ks[j] - val[i])) % mod;
    }
  }}
  exit:
  if (bezkrawedzi[0] != 0 && bezkrawedzi[1] != 0) {
    //dwa grafy
    printf("problem z : %lu %lu \n", bezkrawedzi[0], bezkrawedzi[1]);
  }
}

int main() {
  long n, m, z;
  scanf("%li %li %li", &n, &m, &z);

  Node graph[n];
  for (long i = 0; i < m; i++) {
    long node1, node2;
    scanf("%li %li", &node1, &node2);
    graph[node1 - 1].neighbours.insert(node2 - 1);
    graph[node2 - 1].neighbours.insert(node1 - 1);
  }

  long long ks[z], num_of_options[z];
  fill_n(num_of_options, z, 1);
  for (long i = 0; i < z; i++) {
    long long k;
    scanf("%lli", &ks[i]);
  }

  count_options(graph, ks, num_of_options, n, m, z);

  for(int i = 0; i < z; i++) {
    printf("%lu\n", num_of_options[i]);
  }

  return 0;
}
