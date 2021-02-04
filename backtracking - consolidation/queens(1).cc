// Cuenta todas las manera de poner n damas en un tablero nxn

#include <iostream>
#include <vector>
using namespace std;


//definicion de conceptos y variables
using VE = vector<int>;
int n;
VE colu, dia1, dia2;


//funcion de backtracking que cuenta las formas de colocar n damas sin
//que se amenacen en un tablero nxn

int f(int i) {
    if (i == n) return 1;

    int res = 0;
    for (int j = 0; j < n; ++j) {
//marcador de las diagonales derecha arriba
        int d1 = i + j;
//marcador de las diagonales derecha abajo
        int d2 = i - j + n - 1;
//si la columna o las diagonales estan ocupadas no sigue
        if (not colu[j] and not dia1[d1] and not dia2[d2]) {
//prueba activando una posicion hace el backtracking y luego la
//desactiva para para seguir con la siguiente
            colu[j] = dia1[d1] = dia2[d2] = true;
            res += f(i + 1);
            colu[j] = dia1[d1] = dia2[d2] = false;
        }
    }
    return res;
}


int main() {
    cin >> n;
    colu = VE(n, false);
    dia1 = dia2 = VE(2*n - 1, false);
    cout << f(0) << endl;
}
