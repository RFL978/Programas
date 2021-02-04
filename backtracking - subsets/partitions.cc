#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;


int n, p;
VE num;
VS par;


void escriure() {
	for (int i = 0; i < p; ++i) {
		bool first = false;            //bolea per quadrar les comes ','
		cout << "subset " << i+1 << ": {";
	
		for (int j = 0; j < n; ++j) {			//for modificat per quadrar les comes
			if (num[j] == i and first == true) cout << ',' << par[j];
			else if (num[j] == i) {
				cout << par[j];
				first = true;
			}
		}
		cout << '}';

		cout << endl;
	}
	cout << endl;
	return;
}



void parti(int i) {
	if (i == n) return escriure();
	
	for (int j = 0; j < p; ++j) {  //bucle per incluir les p particions
		num[i] = j;
		parti(i + 1);
	}
}




int main() {
	cin >> n;
	num = VE(n);
	par = VS(n);
	for (int i = 0; i < n; ++i) cin >> par[i];
	cin >> p;
	
	parti(0);
}
