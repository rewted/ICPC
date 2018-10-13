#include <iostream>
#include <vector>
using namespace std;

int main () {
  vector<int> one_set {1, 1, 2, 2, 2, 8};
  vector<int> current_set;
  int temp;
  for (int i = 0; i < 6; i++) {
    cin >> temp;
    current_set.push_back(temp);
  }
  cout << one_set[0] - current_set[0] << " ";
  cout << one_set[1] - current_set[1] << " ";
  cout << one_set[2] - current_set[2] << " ";
  cout << one_set[3] - current_set[3] << " ";
  cout << one_set[4] - current_set[4] << " ";
  cout << one_set[5] - current_set[5] << endl;
  return 0;
}
