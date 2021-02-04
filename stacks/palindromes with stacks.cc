#include <iostream>
#include <stack>
#include <sstream>
using namespace std;




int main() {
    string s;
    while(getline(cin, s)) {
        istringstream ss(s);
        int x;
        stack<int> p1, p2, paux;
        while (ss >> x) {
            p1.push(x);
            paux.push(x);
        }
        for (int i = 0; i < p1.size(); ++i) {
            p2.push(paux.top());
            paux.pop();
        }
        bool nice = true;
        while (not p1.empty()) {
            if (p1.top() != p2.top()) nice = false;
            p1.pop();
            p2.pop();
        }

        cout << "It is ";
        if (not nice) cout << "NOT ";
        cout << "a palindrome." << endl;
    }
}