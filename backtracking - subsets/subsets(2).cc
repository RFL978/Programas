#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;

int n;
int obj;
VE num;
VS par;


void escriure() {
	
	bool first = false;            //bolea per quadrar les comes ','
	cout << '{';
	
	for (int j = 0; j < n; ++j) {			//for modificat per quadrar les comes
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




void backtracking(int i, int sum) {
	
	if (sum > obj or (n - i < obj - sum)) return;  //si es passa delements o ja no pot arribar als necesaris atura el programa
	
	if (i == n and sum == obj) return escriure();	//si compleix els requeriments escriu el vector par
	
	num[i] = 0;											//part de backtracking
	backtracking(i + 1, sum);
	num[i] = 1;
	backtracking(i + 1, sum + 1);
}


int main() {
	cin >> obj >> n;
	
	par = VS(n);
	num = VE(n);
	
	for (int i = 0; i < n; ++i) cin >> par[i];
	
	backtracking(0, 0);
}
