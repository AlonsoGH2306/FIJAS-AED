
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> laberinto(n);
    vector<vector<int>> fuego(n, vector<int>(m, -1));
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> colaFuego;
    queue<pair<int, int>> colaPersona;

    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> laberinto[i];

        for (int j = 0; j < m; j++) {
            if (laberinto[i][j] == 'F') {
                colaFuego.push({i, j});
                fuego[i][j] = 0;
            }

            if (laberinto[i][j] == 'J') {
                x = i;
                y = j;
                colaPersona.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!colaFuego.empty()) {
        auto [f, c] = colaFuego.front();
        colaFuego.pop();

        for (int i = 0; i < 4; i++) {
            int nf = f + df[i];
            int nc = c + dc[i];

            if (nf >= 0 && nf < n && nc >= 0 && nc < m &&
                laberinto[nf][nc] != '#' && fuego[nf][nc] == -1) {

                fuego[nf][nc] = fuego[f][c] + 1;
                colaFuego.push({nf, nc});
            }
        }
    }

    while (!colaPersona.empty()) {
        auto [f, c] = colaPersona.front();
        colaPersona.pop();

        if (f == 0 || f == n - 1 || c == 0 || c == m - 1) {
            cout << dist[f][c] + 1 << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nf = f + df[i];
            int nc = c + dc[i];

            if (nf >= 0 && nf < n && nc >= 0 && nc < m &&
                laberinto[nf][nc] != '#' && dist[nf][nc] == -1 &&
                (fuego[nf][nc] == -1 ||
                 dist[f][c] + 1 < fuego[nf][nc])) {

                dist[nf][nc] = dist[f][c] + 1;
                colaPersona.push({nf, nc});
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
