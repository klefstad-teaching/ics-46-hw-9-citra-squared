#include "dijkstras.h"

int main() {
    Graph G; 
    file_to_graph("src/small.txt", G);

    int n = G.numVertices; 

    vector<int> previous(n, -1);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    
    for (int i = 0; i < n; i++) {
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]); 
    }
}