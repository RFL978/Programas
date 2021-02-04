#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;


int n;
VE num;
int obj;              



void escriure() {
	cout << num[0];						//solucion a los espacios extra
	for (int j = 1; j < n; ++j) {
		cout << ' ' << num[j];
	}
	cout << endl;
}


void backtracking(int i, int sum) {
	
	if (sum > obj or (n - i < obj - sum)) return;   //corta el programa cuando la suma supera el numero de unos
	
	if (i == n) {
		if (sum == obj) escriure();
		return;
	}
	

	num[i] = 0;						//parte de backtracking
	backtracking(i + 1, sum);
	num[i] = 1;
	backtracking(i + 1, sum + 1);
	return;
}



int main() {
  cin >> n >> obj;
  num = VE(n);
  backtracking(0, 0);
}
