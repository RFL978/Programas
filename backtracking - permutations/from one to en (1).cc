#include <iostream>
#include <vector>
#include <algorithm>

using VI = std::vector<int>;

int n;
VI perm, used;


void escriure() {
    std::cout << '(';
    bool first = true;
    for (int x : perm) {
        if (first) first = false;
        else std::cout << ',';
        std::cout << x;
    }
    std::cout << ')' << std::endl;
}


void permus(int i) {
    if (i == n) return escriure();
    
    for (int j = 0; j < n; ++j) {
        if (not used[j]) {
            used[j] = true;
            perm[i] = j+1;
            permus(i+1);
            used[j] = false;
        }
    }
}




int main() {
    std::cin >> n;
    perm = VI(n);
    used = VI(n,0);
    permus(0);
}