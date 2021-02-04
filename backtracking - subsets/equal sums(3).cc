#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;

int goal, n;
VI v;
VB used;


void escriure() {
    bool first = true;
    cout << '{';
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            if (first) first = false;
            else cout << ",";

            cout << v[i];
        }
    }
    cout << '}' << endl;
}


void sumatron(int i, int sum, bool new_elm, int total) {
    if (sum > goal) return; // Si se pasas de la suma para
    if (sum + total < goal) return; // Si ni con todos los elementos que quedan en el vector se puede igualar goal se para

    // Si se iguala goal habiendo añadido un elemento nuevo se escribe.
    // Esta condicion sirve para el caso en que añades un cero y evita que devuelvas lo mismo cuando haces i + 1 pero used[i] = false
    if (sum == goal and new_elm) escriure();

    if (i < n) {
        total -= v[i];
        used[i] = true;
        sumatron(i + 1, sum + v[i], true, total);
        used[i] = false;
        sumatron(i + 1, sum, false, total);
    }
}



int main() {
    cin >> goal >> n;
    v = VI(n);
    used = VB(n);

    int total = 0;
    for (int& e : v) { // Introduce los elementos que te dan en el vector y calcula lo que suman
        cin >> e;
        total += e;
    }
    sumatron(0, 0, true, total);
}