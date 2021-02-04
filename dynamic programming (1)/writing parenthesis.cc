//els nombres de Catalan

#include <iostream>
#include <vector>
using namespace std;


using VE = vector<long long>;
using ME = vector<VE>;


int n;
ME C;


void catalan(int i, int j) {
	if (j == 0 or i == j) {
		C[i][j] = 1;
		return;
	}
	if (C[i][j] == -1) {
		catalan(i-1, j);
		catalan(i-1, j-1);
		C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	return;
}



int main() {
	C = ME(67, VE(67, -1));
	
	while (cin >> n) {
		if (n % 2 == 1) cout << 0 << endl;
		else {
			catalan(n, n/2);
			cout << C[n][n/2] / (n/2 + 1) << endl;
		}
	}
}
