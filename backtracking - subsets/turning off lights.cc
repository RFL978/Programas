#include <iostream>
#include <vector>




using VI = std::vector<int>;
using MI = std::vector<VI>;


MI board;





int onoff(int val, MI &board) {
	int sum = 0;
	for (int i = 0; i < int(board.size()); ++i) {
		for (int j = 0; j < int(board[0].size()); ++j) {
			sum += board[i][j];
		}
	}
	if (sum == 0) return val;
}



int main() {
	int n,m;
	while (std::cin >> n >> m) {
		
		board = MI(n, VI(m));
		
		char r;
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cin >> r;
				if (r == '.') board[i][j] = 0;
				else board[i][j] = 1;
			}
		}
		return onoff(0, board);
	}
}
