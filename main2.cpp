#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int Vertex_number;
    vector<vector<pair<int, int>>> Edge_Lists;

public:
    Graph(int n){
        Vertex_number = n;
        Edge_Lists.resize(Vertex_number);
    }

    void addEdge(int u, int v, int length) {
        Edge_Lists[u].push_back(make_pair(v, length));
        Edge_Lists[v].push_back(make_pair(u, length));
    }

    void dekstra(int start) {
        vector<int> distance(Vertex_number, 999999999);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto neighbor : Edge_Lists[u]) {
                int f = neighbor.first;
                int length = neighbor.second;

                if (distance[f] > distance[u] + length) {
                    distance[f] = distance[u] + length;
                    pq.push(make_pair(distance[f], f));
                }
            }
        }

        for (int i = 0; i < Vertex_number; i++) {
            cout << "Vertex " << i << ": " << distance[i] << endl;
        }
    }
};

int main() {
    Graph g(9);

    g.addEdge(0, 1, 5);
    g.addEdge(0,3,2);
    g.addEdge(1, 2, 5);
    g.addEdge(1,4,2);
    g.addEdge(4, 5, 7);
    g.addEdge(4,8,2);
    g.addEdge(5, 6, 9);
    g.addEdge(6,7,4);
    g.dekstra(0);

    return 0;
}