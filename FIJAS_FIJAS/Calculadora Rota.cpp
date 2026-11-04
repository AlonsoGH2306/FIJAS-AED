
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int limite = 2 * max(a, b) + 2;

    vector<int> dist(limite + 1, -1);
    queue<int> cola;

    dist[a] = 0;
    cola.push(a);

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();

        if (u == b) {
            cout << dist[u] << '\n';
            return 0;
        }

        int v = u * 2;

        if (v <= limite && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            cola.push(v);
        }

        v = u - 1;

        if (v > 0 && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            cola.push(v);
        }
    }

    return 0;
}
