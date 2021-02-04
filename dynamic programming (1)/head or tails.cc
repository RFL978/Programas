#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



using VD = vector<double>;
using VVD = vector<VD>;


int m, n;
VD p;
VVD a;


//retorna la probablilitat que l'anna guanyi despres de que hagin sortit i cares, j creus

double anna(int i, int j) {
	if (i == m) return 1;
	if (j == n) return 0;
	double& res = a[i][j];
	if (res != -1) return res;
	return res = p[j] * anna(i + 1, j) + (1 - p[j]) * anna(i, j + 1);
}



int main() {
	while(cin >> m >> n) {
		p = VD(n);
		for (double& pi : p) cin >> pi;       // == for (int i = 0; i < n; ++i) cin >> p[i]
		a = VVD(m, VD(n, -1));
		cout << fixed << setprecision(4) << anna(0, 0) << endl;
	}
}
