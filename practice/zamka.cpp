#include <iostream>

using namespace std;

int sum(int a) {
  int total = 0;
  while (a > 0) {
    total += a%10;
    a /= 10;
  }
  return total;
}

int main () {
  int l;
  int d;
  int x;
  cin >> l;
  cin >> d;
  cin >> x;
  while (sum(l) != x) {
    l++;
    if (l > 10000 || l > d) {
      break;
    }
  }
  while (sum(d) != x) {
    d--;
    if (d < 1) {
      break;
    }
  }
  cout << l << endl << d << endl;  
  
  return 0;
}
