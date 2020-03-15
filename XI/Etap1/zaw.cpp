#include <iostream>
#include <list>
#include <stack>

using namespace std;

struct Edge {
    int destination;
    int value;
};

struct Node {
    bool visited;
    List<Edge> neighbours;
};

int main() {
    //Getting input
    int n, m;
    scanf("%i %i", &n, &m);

    Node graph[n];

    //Creating Graph
    for (int i = 0; i < m; i++) {
        int node1, node2, val1, val2;
        scanf("%i %i %i %i", &node1, &node2, &val1, &val2);
        Edge edge1, edge2;
        edge1.destination = node2 - 1;
        edge1.value = val1;
        edge2.destination = node1 - 1;
        edge2.value = val2;
        graph[node1 - 1].neighbours.add(edge1);
        grapg[node2 - 1].neighbours.add(edge2);
    }

    //Starting Dijkstra algorithm

    //printing output

    return 0;
}