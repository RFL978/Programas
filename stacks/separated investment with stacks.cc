#include <iostream>
#include <stack>
#include <sstream>
using namespace std;



int main() {
	string s;
	while (getline(cin, s)) { // getline(cin, s) recoge todos los chars hasta un '\n' o hasta que se acabe el programa y los introduce en s
		istringstream ss(s); // ni idea de qué hace
		int x;
		stack<int> odd, even;
		while (ss >> x) {
			if (x % 2 == 0) even.push(x);
			else odd.push(x);
		}
		while (not even.empty()) {
			cout << even.top(); even.pop();
			cout << (even.empty() and odd.empty() ? "" : " ");
		}

		while (not odd.empty()) {
			cout << odd.top(); odd.pop();
			cout << (odd.empty() ? "" : " ");
		}
		cout << endl;
	}
}