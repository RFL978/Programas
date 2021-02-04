#include <iostream>
#include <vector>
using namespace std;


using ll = unsigned long long;
using VE = vector<ll>;



VE F;
int n, m;
const int MAX = 1e3;



int main() {
	F = VE(MAX + 1);
	F[0] = 0;
	F[1] = 1;
	
	
	while(cin >> n >> m) {
		for (int i = 2; i <= n; ++i) F[i] = (F[i-1] + F[i-2]) % m;
		cout << F[n] << endl;
	}
}
