#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;


int n;
VS par;
VE num;


void escriure() {
	
	bool first = false;
	cout << '{';
	
	for (int j = 0; j < n; ++j) {
		if (num[j] == 1 and first == true) cout << ',' << par[j];
		else if (num[j] == 1) {
			cout << par[j];
			first = true;
		}
	}
	cout << '}';

	cout << endl;
	return;
}


void backtracking(int i) {
	
	if (i == n) return escriure();
	
	num[i] = 0;
	backtracking(i + 1);
	num[i] = 1;
	backtracking(i + 1);
	return;
}




int main() {
	cin >> n;
	
	par = VS(n);
	num = VE(n);

		
	for (int i = 0; i < n; ++i) cin >> par[i];
	
	backtracking(0);
}
