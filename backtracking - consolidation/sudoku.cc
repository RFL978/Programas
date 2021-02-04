//programa que recibe un numero n, seguido de n sudokus 9x9 no completos que resuelve y luego escribe
#include <iostream>
#include <vector>


using VE = std::vector<int>;
using VVE = std::vector<VE>;
using VVVE = std::vector<VVE>;


VVE M(9, VE(9));
VVE fila; //matriz que guarda que numeros se han utilizado y en que fila
VVE colu; //matriz que guarda que numeros se han utilizado y en que columna
VVVE quad; //3matriz que guarda que numeros se han utilizado y en que cuadrante


//funcion que escribe la matriz
void escriure() {
    std::cout << std::endl;
    for (int i = 0; i < 9; ++i) {
        // si j==0 ==> j==false; si j!=0 ==> j==true
        for (int j = 0; j < 9; ++j) std::cout << (j ? " " : "") << M[i][j];
        std::cout << std::endl;
    }
}

//funcion que recorre la matriz M por columnas añadiendo elementos nuevos recursivamente
bool sudoku(int i, int j) {

    if (j == 9) return sudoku(i + 1, 0); //si se llega al final de una fila comienza por la siguiente

    if (i == 9) { //si se llega al final de la matriz se llama a escriure()
        escriure();
        return true;
    }
    //si ya hay un elemento en la matriz pasa al la siguiente (son los elementos dados inicialmente)
    if (M[i][j]) return sudoku(i, j + 1);

    for (int x = 1; x <= 9; ++x)
        //si el valor de x NO esta en dicha columna, fila o cuadrante
        if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
            //marca la x en dicha columna, fila y cuadrante
            fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
            //coloca x en esa posicion
            M[i][j] = x;
            //mira la siguiente casilla
            if (sudoku(i, j + 1)) return true;
            //sobreescribe el valor a 0 y lo desmarca en la columna, fila y cuadrante para asi poder probar con otros valores
            M[i][j] = 0;            
            fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
        }    
    return false;
}


int main() {
    int t;
    std::cin >> t;
    std::cout << t << std::endl;
    while (t--) {
        fila = colu = VVE(9, VE(10, false));
        quad = VVVE(3, VVE(3, VE(10, false)));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                char c;
                std::cin >> c;
                if (c == '.') M[i][j] = 0;
                else {
                    int x = c - '0';
                    M[i][j] = x;
                    fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
                }
            }
        sudoku(0, 0);
    }
}
