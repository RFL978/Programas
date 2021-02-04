#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using ME = vector<VE>;


int n, m;
char r;
ME maze;


int exit(int i, int sum) {
	
}


int main() {
	cin >> n >> m;
	
	while (n != 0) {
		maze = ME(n, VE(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> r;
				if (r == '.') maze[i][j] = 0;
				else maze[i][j] = -1;
			}
		}
		//cout << exit(0, 0) << endl;
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << maze[i][j];
			}
			cout << endl;
		}
	}
}
