#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

VI coins = {50, 20, 10, 5, 2, 1};
VI change;


void possibilities(int imax, int n) {
    if (n < 0) return;
    if (n == 0) {
        for (int i = 0; i < int(change.size()); ++i) {
            cout << (i != 0 ? " " : "") << change[i];
        }
    cout << endl;
    }
    for (int i = imax; i < 6; ++i) {
        change.push_back(coins[i]);
        possibilities(i, n - coins[i]);
        change.pop_back();
    }
}


int main() {
    int n;
    while (cin >> n) {
        possibilities(0, n);
        cout << endl;
    }
}