#include <iostream>

using namespace std;

int main () {
  int left;
  int right;

  cin >> left;
  cin >> right;

  if (left == right && left != 0) {
    cout << "Even " << left * 2 << endl;
  }
  if (left > right && left != 0) {
    cout << "Odd " << left * 2 << endl;
  }
  if (right > left && right != 0) {
    cout << "Odd " << right * 2 << endl;
  }
  if (right == 0 && left == 0) {
    cout << "Not a moose" << endl;
  }

  return 0;
}
