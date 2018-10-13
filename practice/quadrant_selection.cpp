#include <iostream>

using namespace std;

int main () {
  int x;
  int y;
  cin >> x;
  cin >> y;

  // quad 1
  if (x > 0 && y > 0) {
    cout << 1 << endl;
  }

  // quad 2
  if (x < 0 && y > 0) {
    cout << 2 << endl;
  }

  // quad 3
  if (x < 0 && y < 0) {
    cout << 3 << endl;
  }

  // quad 4
  if (x > 0 && y < 0) {
    cout << 4 << endl;
  }
  
  return 0;
}
