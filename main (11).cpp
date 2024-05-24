#include <iostream>
#include <list>
using namespace std;

class Graph {
    int Vertex_number;
    list<int> *Edge_Lists;
    bool *visited;

public:
    Graph(int n) {
        Vertex_number = n;
        Edge_Lists = new list<int>[n];
        visited = new bool[n];
        for(int i = 0; i < n; i++)
            visited[i] = false;
    }
    void addEdge(int start, int finish) {
        Edge_Lists[start].push_back(finish);
    }
    void DFS(int start_vertex){
        visited[start_vertex] = true;
        cout << start_vertex << " ";
        list<int>::iterator i;
        for (i = Edge_Lists[start_vertex].begin(); i != Edge_Lists[start_vertex].end(); i++) {
            if (!visited[*i]) {
                DFS(*i);
            }
        }
        visited = new bool[Vertex_number];
        for(int i = 0; i < Vertex_number; i++)
            visited[i] = false;
    }
    void BFS(int start_vertex) {
        list<int> visit;
        visited[start_vertex] = true;
        visit.push_back(start_vertex);

        while(!visit.empty()) {
            start_vertex = visit.front();
            cout << start_vertex << " ";
            visit.pop_front();
            list<int>::iterator i;
            for (i = Edge_Lists[start_vertex].begin(); i != Edge_Lists[start_vertex].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    visit.push_back(*i);
                }
            }
        }
        visited = new bool[Vertex_number];
        for(int i = 0; i < Vertex_number; i++)
            visited[i] = false;
    }
};



int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.DFS(0);
    g.BFS(0);

}