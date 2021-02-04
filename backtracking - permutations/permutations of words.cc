#include <iostream>
#include <vector>

using VS = std::vector<std::string>;
using VI = std::vector<int>;

int n; //cantidad de palabras que contendra el vector
VS perm, container;
VI used;


void escriure() {
    std::cout << '(';
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (first) first = false;
        else std::cout << ',';
        std::cout << perm[i];
    }
    std::cout << ')' << std::endl;
}



void permus(int i) {
    if (i == n) return escriure();

    for (int j = 0; j < n; ++j) {
        if (not used[j]) {
            used[j] = true;
            perm[i] = container[j];
            permus(i+1);
            used[j] = false;
        }
    }
}



int main() {
    std::cin >> n;
    perm = VS(n);
    container = VS(n);
    used = VI(n, 0);
    for (int i; i < n; ++i) std::cin >> container[i];

    permus(0);
}