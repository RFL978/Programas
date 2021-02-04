#include <iostream>
#include <vector>


using VI = std::vector<int>;





void finished(int current, int i, VI vec) {
	if (i == int(vec.size())-2) {
		std::cout << current << endl;
		return;
	}
	current -= vec[i];
	if (current >= -vec[n]/2) finished(current, i+1, vec);
	current += 2*vec[i];
	if (current <= vec[n]/2) finished(current, i+1, vec);
	return;
}



int main() {
	std::cout << "void" << endl;
	
	int length, n, l;
	VI jumps;
	std::cin >> length >> n;
	jumps = VI(n+1);
	jumps[n] = length;
	for (int i = 0; i < n; ++i) {
		std::cin >> l;
		jumps[i] = l;
	}
	
	return finished(0, 0, jumps);
}
