#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VE = vector<int>;


int n;
VE num;
int obj;
VE triat;
bool franchesco = 0;

bool criterion(int i, int j) {
    return i > j;
}

void escriu() {
    cout << '{';
    bool primer = true;
    for (int i = 0; i < n; ++i) {
      if (triat[i]) {
        if (primer) primer = false;
        else cout << ',';
        cout << num[i];
      }
    } 
  cout << '}' << endl;
  franchesco = 1;
}


void f(int i, int sum) {
    if (franchesco == 1) return;
    if (i == n) {
    if (sum == obj) escriu();
    return;
  }


  triat[i] = true;
  f(i + 1, sum + num[i]);
  triat[i] = false;
  f(i + 1, sum);
}


int main() {
  cin >> obj >> n;
  num = VE(n);
  for (int& x : num) cin >> x;
  triat = VE(n);
  sort(num.begin(), num.end(), criterion);
  f(0, 0);
  if (franchesco == 0) {
      cout << "no solution" << endl;
  }
}
