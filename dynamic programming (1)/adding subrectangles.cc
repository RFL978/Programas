//agafa un rectangle de lletres majuscules i el retorna amb el valor de cada casella
#include <iostream>
#include <vector>
using namespace std;



int main() {
  vector<int> value('Z' - 'A' + 1);
  value[0] = 1;
  //bucle per donar el valor de cada majuscula
  for (int k = 1; k < int(value.size()); ++k) value[k] = value[k-1] + k + 1;
  vector<string> m; //vector que a cada posicio conte les files del rectangle donat
  string line;
  while (cin >> line) m.push_back(line);

  int r = m.size();
  int c = m[0].size();

  //matriu que conte els valors del rectangle, te una fila i una columna mes per poder fer el bucle seguent
  //sense haver de modificar-lo (l'element que li sumes per l'esquerra/per dalt es 0 a la primera columna/fila)
  vector<vector<int>> s(r+1, vector<int>(c+1, 0));

  //suma l'element just de sobre amb el de just a l'esquerra, resta
  //l'element [i-1][j-1] i suma el valor de la lletra de la casella
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1]
	+ value[m[i-1][j-1] - 'A'];
    }
  }
  //imprimeix els rectangle
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cout << (j > 1 ? " " : "") << s[i][j];
    }
    cout << endl;
  }
}
