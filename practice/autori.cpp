#include <iostream>
#include <string>
using namespace std;

int main () {
  string buffer;
  cin >> buffer;
  for (auto x : buffer) {
    if (x >= 65 && x <= 90) {
      cout << x;
    }
  }
  cout << endl;
  return 0;
}
