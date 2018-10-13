#include <iostream>
#include <cmath>

using namespace std;

int main () {
  int articles;
  int impact_factor;
  int scientists;
  
  cin >> articles;
  cin >> impact_factor;

  scientists = articles * (impact_factor-1) + 1;

  cout << scientists << endl;
  
  return 0;
}
