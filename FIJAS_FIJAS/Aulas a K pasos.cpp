
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, s, k;
    cin >> n >> m >> s >> k;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> cola;

    dist[s] = 0;
    cola.push(s);

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                cola.push(v);
            }
        }
    }

    int respuesta = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            respuesta++;
        }
    }

    cout << respuesta << '\n';

    return 0;
}
