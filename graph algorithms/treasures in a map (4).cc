#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, maximum = 0;
vector<string> map;
vector<vector<int>> viewed;

vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};


void distance(int r0, int c0) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[r0][c0] = 0;
    q.push({r0, c0});
    while (not q.empty()) {
        auto x = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int r = x.first + dr[k];
            int c = x.second + dc[k];
            if (r >= 0 and r < n and c >= 0 and c < m and map[r][c] != 'X' and dist[r][c] == -1) {
                dist[r][c] = dist[x.first][x.second] + 1;
                if (map[r][c] == 't') maximum = dist[r][c];
                q.push({r,c});
            }
        }
    }
}


int main() {
    cin >> n >> m;
    map = vector<string>(n);
    for (auto& row : map) cin >> row;
    int r, c;
    cin >> r >> c;

    distance(r - 1, c - 1);
    if (maximum) cout << "maximum distance: " << maximum << endl;
    else cout << "no treasure can be reached" << endl;
}