#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;

int n;
VI elements;


int main() {
    while (cin >> n) {
        elements = VI(n);
        for (int& e : elements) cin >> e;
    }
}