//dados dos strings, uno de n consonantes y otro de n vocales, escribe todas
//las permutaciones que se pueden conseguir alternando consonantes y vocales
#include <iostream>
#include <vector>
using namespace std;

using VS  = vector<string>;
using VI  = vector< int>;
using VVI = vector< VI>;

int n; //indica la cantidad de consonantes y vocales que se tienen
VS l; //guarda dos strings, la primera contiene todas las consonantes y la segunda todas las vocales
string s; //guarda las palabras obtenidas con las permutaciones
VVI u; //u[0] u[1] contienen que consonantes y vocales se han usado respectivamente

void perm(int k) {
  //cuando se usan todas las letras se escribe la permutacion obtenida
  if (k == 2*n) {
    cout << s << endl;
    return;
  }
  //sirve para escoger entre consonantes y vocales cogiendo l[0] en los multiplos de dos y l[1] en el resto
  string& lletra = l[k%2];
  //sirve para escoger entre consonantes y vocales cogiendo u[0] en los multiplos de dos y u[1] en el resto
  VI& usat = u[k%2];

  //mira todos los elementos dentro del grupo que toque (consonantes/vocales) colocando
  //el primero que encuentra que no se haya usado previamente e inicia otro ciclo recursivo
  for (int j = 0; j < n; ++j)
    if (not usat[j]) {
      usat[j] = true;
      s[k] = lletra[j];
      perm(k+1);
      usat[j] = false;
    }
}

int main() {
  cin >> n;
  l = VS(2);
  cin >> l[0] >> l[1];
  s = string(2*n, ' ');
  u = VVI(2, VI(n, false));
  perm(0);
}
