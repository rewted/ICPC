#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;
  int a = 1;
  int b = 0;
  int c = 0;
  for (auto x : s){
    
    switch(x) {
    case 'A':
      b ^= a;
      a ^= b;
      b ^= a;
      break;
    case 'B':
      c ^= b;
      b ^= c;
      c ^= b;
      break;
    case 'C':
      c ^= a;
      a ^= c;
      c ^= a;
      break;
    default:
      break;
    }
  }
  if (a) {
    cout << 1 << endl;
  }
  if (b) {
    cout << 2 << endl;
  }
  if (c) {
    cout << 3 << endl;
  }
}
