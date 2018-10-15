#include <iostream>

using namespace std;

int main () {
  int num_matches;
  int width;
  int height;
  int max_length;
  int temp;

  cin >> num_matches;
  cin >> width;
  cin >> height;
  // a^2 + b^2 gives us c^2 which is hypot.
  max_length = width * width + height * height;
  
  for (int i = 0; i < num_matches; i++) {
    cin >> temp;
    if (temp * temp <= max_length) {
      cout << "DA" << endl;
    }
    else {
      cout << "NE" << endl;
    }
  }
  return 0;
}
