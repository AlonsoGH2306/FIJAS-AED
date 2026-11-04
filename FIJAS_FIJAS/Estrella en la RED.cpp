
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> grado(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        grado[u]++;
        grado[v]++;
    }

    bool estrella = false;

    if (m == n - 1) {
        for (int i = 1; i <= n; i++) {
            if (grado[i] == n - 1) {
                estrella = true;
                break;
            }
        }
    }

    cout << (estrella ? "SI" : "NO") << '\n';

    return 0;
}
