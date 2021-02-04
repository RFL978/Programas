#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<string> mapa;
vector<vector<int>> vis; // de visitat


bool arribo(int f, int c) {
    if (f < 0 or f >= n or c < 0 or c >= m or mapa[f][c] == 'X' or vis[f][c]) return false; // vist[f][c]: Si en una crida anterior ja es veu un vertex, aquella crida ja retornara cert
    vis[f][c] = true;
    if (mapa[f][c] == 't') return true;
    return
        arribo(f - 1, c) or
        arribo(f + 1, c) or
        arribo(f, c - 1) or
        arribo(f, c + 1);
}



int main() {
    cin >> n >> m;
    mapa = vector<string>(n);
    for (auto& fila : mapa) cin >> fila;
    int f, c;
    cin >> f >> c;
    vis = vector<vector<int>>(n, vector<int>(m, false));
    if (arribo(f - 1, c - 1)) cout << "yes" << endl;
    else cout << "no" << endl;
}