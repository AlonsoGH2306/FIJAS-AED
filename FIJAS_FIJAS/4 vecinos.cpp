
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> matriz(n);

    for (int i = 0; i < n; i++) {
        cin >> matriz[i];
    }

    int fi, ci, ff, cf;
    cin >> fi >> ci >> ff >> cf;

    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> cola;

    dist[fi][ci] = 0;
    cola.push({fi, ci});

    while (!cola.empty()) {
        int f = cola.front().first;
        int c = cola.front().second;
        cola.pop();

        if (f == ff && c == cf) {
            cout << dist[f][c] << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nf = f + df[i];
            int nc = c + dc[i];

            if (nf >= 0 && nf < n && nc >= 0 && nc < m &&
                matriz[nf][nc] != '#' && dist[nf][nc] == -1) {

                dist[nf][nc] = dist[f][c] + 1;
                cola.push({nf, nc});
                }
        }
    }

    cout << -1 << '\n';

    return 0;
}
