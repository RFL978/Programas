#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VVE = vector<VE>;

int n, x;
VVE C;



void bin(int i, int j) {
	if (i == j or j == 0) {
		C[i][j] = 1;
		return;
	}
	if (C[i][j] == -1) {
		bin(i-1,j-1);
		bin(i-1,j);
		C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	return;
}



int main() {
	
	C = VVE(30 + 1, VE(30 + 1, -1));
	
	while (cin >> n >> x) {
		bin(n, x);
		cout << C[n][x] << endl;
	}
}
