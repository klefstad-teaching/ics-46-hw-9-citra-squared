#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices; 

    vector<int> distances(n, INF);
    vector<int> visited(n, false); 

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source)); 

    distances[source] = 0;

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr]) {
            continue;
        } else {
            visited[curr] = true; 

            for (Edge edge : G[curr]) {
                int next = edge.dst;
                int weight = edge.weight; 

                if (!visited[next] && distances[curr] + weight < distances[next]) {
                    distances[next] = distances[curr] + weight;
                    previous[next] = curr; 
                    pq.push(make_pair(distances[next], next));
                }
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> shortest_path; 
    for (int d = destination; d != -1; d = previous[d]) {
        shortest_path.push_back(d);
    }
    std::reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path; 
}

void print_path(const vector<int>& v, int total) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << endl; 
    std::cout << "Total cost is " << total << std::endl; 
    
}  