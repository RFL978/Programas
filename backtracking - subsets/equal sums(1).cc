#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;


int n;
VE num;
int obj;
VE triat;


void escriu() {
    cout << '{';
    bool primer = true;
    for (int i = 0; i < n; ++i)
    if (triat[i]) {
      if (primer) primer = false;
      else cout << ',';
      cout << num[i];
    }
  cout << '}' << endl;
}


void f(int i, int sum) {
  if (i == n) {
    if (sum == obj) escriu();
    return;
  }

  triat[i] = false;
  f(i + 1, sum);
  triat[i] = true;
  f(i + 1, sum + num[i]);
}


int main() {
  cin >> obj >> n;
  num = VE(n);
  for (int& x : num) cin >> x;
  triat = VE(n);
  f(0, 0);
}
