#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = INT_MAX;

bool bfs(vector<vector<int>>& f, vector<vector<int>>& c, vector<int>& d, int s, int t) {
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < c.size(); ++v) {
            if (f[u][v] < c[u][v] && d[v] == INF) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }

    return d[t] != INF;
}

int dfs(vector<vector<int>>& f, vector<vector<int>>& c, vector<int>& d, vector<int>& p, int u, int minC, int t) {
    if (u == t || minC == 0) {
        return minC;
    }

    for (int& v = p[u]; v < c.size(); ++v) {
        if (d[v] == d[u] + 1) {
            int delta = dfs(f, c, d, p, v, min(minC, c[u][v] - f[u][v]), t);
            if (delta != 0) {
                f[u][v] += delta;
                f[v][u] -= delta;
                return delta;
            }
        }
    }

    return 0;
}

int findMaxFlow(vector<vector<int>>& f, vector<vector<int>>& c, int s, int t) {
    int maxFlow = 0;
    vector<int> d(c.size());
    vector<int> p(c.size());

    while (bfs(f, c, d, s, t)) {
        fill(p.begin(), p.end(), 0);
        int flow = dfs(f, c, d, p, s, INF, t);
        while (flow != 0) {
            maxFlow += flow;
            flow = dfs(f, c, d, p, s, INF, t);
        }
    }

    return maxFlow;
}

int main() {
    int n = 6; // Количество вершин в графе
    vector<vector<int>> f(n, vector<int>(n)); // Потоки
    vector<vector<int>> c(n, vector<int>(n)); // Пропускные способности

    // Инициализация графа сети

    // Вызов функции для поиска максимального потока
    int source = 0; // Исток
    int sink = n - 1; // Сток
    int maxFlow = findMaxFlow(f, c, source, sink);

    cout << "Максимальный поток в сети: " << maxFlow << endl;

    return 0;
}
