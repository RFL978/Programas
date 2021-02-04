//programa que devuelve todos los multiconjuntos no ordenados de tamaño t con los n primeros numeros

#include <iostream>
#include <vector>
using namespace std;



using VE = vector<int>;

int n, t;
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


void multi(int i, int sum) {
	if (sum > t) return;
	if (i == n ) {
		if (sum == t) return escriure();
		else return;
	}
	
	for (int j = 0; j <= t; ++j) {  
		num[i] = j;
		multi(i + 1, sum + j);
	}
	return;
}




int main() {
	cin >> n >> t;
	num = VE(n);
	
	multi(0, 0);
}
