#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const vector<int> di = {0, 1, 0, -1};
const vector<int> dj = {1, 0, -1, 0};


int main() {
    int n, m;
    while (cin >> n >> m) {
        int it, jt;
        it = jt = -1;
        vector<vector<char>> t(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> t[i][j];
                if (t[i][j] == 'T') {
                    it = i;
                    jt = j;
                }
            }
        }
        if (it == -1) {
            cout << "El telecos ha fugit." << endl;
        }
        else {
            queue<pair<int, int>> q;
            vector<vector<int>> d(n, vector<int>(m, -1));
            q.push({0, 0});
            d[0][0] = 0;
            while (not q.empty()) {
                auto x = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int i = x.first + di[k];
                    int j = x.second + dj[k];
                    if (i >= 0 and i < n and j >= 0 and j < m and t[i][j] != '#') {
                        if (d[i][j] == -1) {
                            q.push({i, j});
                            d[i][j] = d[x.first][x.second] + 1;
                        }
                    }
                }
            }
            if (d[it][jt] == -1) cout << "El telecos esta amagar" << endl;
            else cout << d[]
        }
    }
}


// Adaptar el codi per tal que quan es troba al telecos es pari