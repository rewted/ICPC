#include <iostream>
#include <string>

int min (int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  }
  if (b <= a && b <= c) {
    return b;
  }
  return c;  
}

using namespace std;

int main () {
  string s;
  cin >> s;
  int t = 0;
  int c = 0;
  int g = 0;

  for (auto x : s) {
    if (x == 'T') {
      t++;
    }
    if (x == 'C') {
      c++;
    }
    if (x == 'G') {
      g++;
    }
  }
  int sets = min(t, c, g);
    
  
  cout << t * t + c * c + g * g + sets * 7<< endl;
  return 0;
}
