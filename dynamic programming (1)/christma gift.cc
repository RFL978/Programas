//Dados (while cin >> n) casos con n segmentos en cada caso, con m_i cantidades de setas en cada uno de los segmentos
//y q posibilidades respecto al inicio y final del recorrido. Enumera cuantas setas recoge en cada posibilidad
#include <iostream>
#include <vector>
using namespace std;



int main() {
  int n; //cantidad de segmentos en cada caso
  int q; //posibilidades en la localizacion del inicio y el final en cada caso
  int cas = 0; //contador de casos
  while (cin >> n) {
    cout << "#" << ++cas << endl;
    vector<int> s(n+1, 0); //contenedor de las sumas parciales
    //guarda una sucesion de sumas parciales de las cantidades de setas en cada segmento
    for (int i = 1; i <= n; ++i) {
      int b;
      cin >> b;
      s[i] = s[i-1] + b;
    }
    cin >> q;
    //para cada caso mira si inicio <= final y resta los terminos correspondientes de la sucesion de sumas parciales
    for (int k = 0; k < q; ++k) {
      int p, c;
      cin >> p >> c;
      if (p > c) swap(p, c);
      cout << s[c] - s[p-1] << endl;
    }
  }
}



//resumen main programa:
//crea un vector con la sucesion de sumas parciales respecto a la cantidad de setas en los segmentos 1 hasta n
//entonces mira que el inicio sea mas pequeño que el final y los resta lo que la lo mismo que si sumaras el valor
//de todos los segmentos desde la salida hasta el final