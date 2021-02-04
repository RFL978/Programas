#include <iostream>
#include <vector>


using VI = std::vector<int>;


int n;
VI perm, col, diag1, diag2;


void escriure() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << (j == perm[i] ? 'Q' : '.');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void queens(int i) {
    if (i == n) return escriure();

    for (int j = 0; j < n; ++j) {
        int d1 = i + j;
        int d2 = i - j + n - 1;
        if (not col[j] and not diag1[d1] and not diag2[d2]) {
            col[j] = diag1[d1] = diag2[d2] = true;
            perm[i] = j;
            queens(i+1);
            col[j] = diag1[d1] = diag2[d2] = false;
        }
    }
}


int main() {
    std::cin >> n;
    perm = VI(n);
    col = VI(n, false);
    diag1 = diag2 = VI(2*n-1, false);
    queens(0);
}