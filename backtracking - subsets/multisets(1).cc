//programa que devuelve todos los multiconjuntos no ordenados de n numeros con x repeticiones

#include <iostream>
#include <vector>
using namespace std;



using VE = vector<int>;

int n, x;
VE num;


void escriure() {
	cout << '{';
	
	bool first = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < num[i]; ++j) {
			if (not first) cout << ',';
			cout << i + 1;
			first = false;
		}
	}
	cout << '}' << endl;
}


void multi(int i) {
	if (i == n) return escriure();
	
	for (int j = 0; j <= x; ++j) {  //pueden haber 0, 1, 2, ... , x elementos. Incluido ese x (por eso el =)
		num[i] = j;
		multi(i + 1);
	}
	return;
}




int main() {
	cin >> n >> x;
	num = VE(n);
	
	multi(0);
}
