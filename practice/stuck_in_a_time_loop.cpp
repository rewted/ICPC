#include <iostream>
#include <string>

using namespace std;

int main () {
  string s = "Abracadabra";
  int count;

  cin >> count;

  for (int i = 1; i <= count; i++) {
    cout << i << " " << s << endl;
  }

  
  return 0;
}
