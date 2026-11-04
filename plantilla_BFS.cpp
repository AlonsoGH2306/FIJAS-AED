#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void bfsArreglo(int n, int s, const vector<vector<int>>& adj, vector<int>& dist, vector<int>& padre) {
    dist.assign(n + 1, INF);
    padre.assign(n + 1, -1);
    vector<int> cola(n);

    dist[s] = 0;
    cola[0] = s;
    int ini = 0;
    int fin = 1;

    while (ini < fin) {
        int u = cola[ini];
        ini++;

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                padre[v] = u;
                cola[fin] = v;
                fin++;
            }
        }
    }
}

vector<int> obtenerCamino(int t, const vector<int>& dist, const vector<int>& padre) {
    if (dist[t] == INF) {
        return {};
    }

    vector<int> c;
    int v = t;
    while (v != -1) {
        c.push_back(v);
        v = padre[v];
    }

    reverse(c.begin(), c.end());
    return c;
}

void contarCaminosMinimos(int n, int s, const vector<vector<int>>& adj, vector<int>& dist, vector<int>& cnt) {
    dist.assign(n + 1, INF);
    cnt.assign(n + 1, 0);
    vector<int> Q;

    dist[s] = 0;
    cnt[s] = 1;
    Q.push_back(s);

    size_t head = 0;
    while (head < Q.size()) {
        int u = Q[head++];

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                Q.push_back(v);
            }
            if (dist[v] == dist[u] + 1) {
                cnt[v] += cnt[u];
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n + 1);

    auto agregarArista = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    agregarArista(1, 2);
    agregarArista(1, 3);
    agregarArista(2, 4);
    agregarArista(3, 4);
    agregarArista(4, 5);

    vector<int> dist, padre;
    bfsArreglo(n, 1, adj, dist, padre);

    int destino = 5;
    cout << "Distancia de 1 a " << destino << ": " << dist[destino] << "\n";

    vector<int> camino = obtenerCamino(destino, dist, padre);
    cout << "Camino: ";
    for (int nodo : camino) {
        cout << nodo << " ";
    }
    cout << "\n";

    vector<int> distCnt, cnt;
    contarCaminosMinimos(n, 1, adj, distCnt, cnt);

    cout << "Numero de caminos minimos de 1 a " << destino << ": " << cnt[destino] << "\n";

    return 0;
}