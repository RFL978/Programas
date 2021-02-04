#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;


int n;
VE V;

void escriure() {
	int y = 0;
	for (int x : V) {
		cout << x;
		if (y < n - 1) cout << ' ';
		++y;
	}
	cout << endl;
}


void backtracking(int i) {
	if (i == n) return escriure();
	V[i] = 0;
	backtracking(i + 1);
	V[i] = 1;
	backtracking(i + 1);
}



int main() {
	cin >> n;
	V = VE(n);
	backtracking(0);
}

