#include <iostream>
#include <vector>

using namespace std;

const int maxx = INT_MAX;
vector<int> g[maxx];
vector<int> match1, match2;
vector<bool> used;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : g[v]) {
        if (match2[to] == -1 or dfs(match2[to])) {
            match1[v] = to;
            match2[to] = v;
            return true;
        }
    }
    return false;
}

int kuhn(int n, int m) {
    match1.assign(n, -1);
    match2.assign(m, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        used.assign(n, false);
        if (dfs(i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m, edges;
    cin >> n >> m >> edges; // Кол-во вершин в первой и второй доле, кол-во всевозможных сочетаний
    for (int i = 0; i < edges; i++) {
        int f, s;
        cin >> f >> s;
        g[f].push_back(s);
    }

    int max_match = kuhn(n, m);
    cout << "Max matching: " << max_match << endl;
}
