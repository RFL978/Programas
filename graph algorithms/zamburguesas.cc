#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

using VI = vector<int>;
using VRoc = vector<Roca>;

struct Roca {
    double x, y, r;
};

VRoc roc();
int n;
double d;

// Retorna la distancia euclidea entre dues roques
double distancia(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool es_pot_saltar(int u, int v) {
    double distancia_entre_centres = distancia(roc[u].x, roc[u].y, roc[v].x, roc[v].y);
    return distancia_entre_centres - roc[u].r - roc[v].r <= d;
}



int main() {
    while (cin >> n >> d) {
        roc = VRoc(n);
        for (auto& r : roc) {
            cin >> r.x >> r.y >> r.r;
        }
        queue<int> q;
        VI dist(n, -1);
        q.push(0);
        dist[0] = 0;

        while (not q.empty()) {
            int f = q.front();
            q.pop();
            if (f == n - 1) break;
            for (int u = 0; u < n; ++u) {
                if (es_pot_saltar(f, u) and dist[u] == -1) {
                    q.push(u);
                    dist[u] = dist[f] + 1;
                }
            }
        }
        if (dist[n-1]) cout << "Xof!" << endl;
        else cout << dist[n-1] << endl;
    }
}
