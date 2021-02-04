#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<string> mapa;
vector<vector<int>> vis; // de visitat

vector<int> df = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};


int distancia(int f0, int c0) {
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[f0][c0] = 0;
    q.push({f0, c0});
    while (not q.empty()) {
        auto x = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int f = x.first + df[k];
            int c = x.second + dc[k];
            if (f >= 0 and f < n and c >= 0 and c < m and mapa[f][c] != 'X' and dist[f][c] == -1) {
                dist[f][c] = dist[x.first][x.second] + 1;
                if (mapa[f][c] == 't') return dist[f][c];
                q.push({f,c});
            }
        }
    }
    return -1;
}





int main() {
    cin >> n >> m;
    mapa = vector<string>(n);
    for (auto& fila : mapa) cin >> fila;
    int f, c;
    cin >> f >> c;

    int d = distancia(f - 1, c - 1);
    if (d == -1) cout << "no treasure can be reached" << endl;
    else cout << "minimum distance: " << d << endl;
}