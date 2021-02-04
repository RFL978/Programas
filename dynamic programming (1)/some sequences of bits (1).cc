#include <iostream>
#include <vector>
using namespace std;

const int MAX = 151;

using ll = long long;
using VL = vector<ll>;


VL Z(MAX, -1);
VL U(MAX, -1);


ll un(int n, int i);


// # secuencias correctas de n bits que acaban en 0
ll zero(int n) {
    ll& res = Z[n];
    if (res != -1) return res;
    if (n == 1) return res = 1;
    return res = un(n - 1, 1);
}


// # secuencias correctas de n bits que acaban en 1
ll un(int n, int i) {
    ll& res = U[n];
    if (res != -1) return res;
    if (n == 1) return res = 1;

    if (i < 2) return res = zero(n - 1) + un(n - 1, i + 1);
    return res = zero(n - 1);
}








int main() {
    int n;
    while (cin >> n) cout << zero(n) + un(n, 1) << endl;
}