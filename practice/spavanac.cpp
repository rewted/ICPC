#include <iostream>

using namespace std;

int main () {
  int hour;
  int minute;

  cin >> hour;
  cin >> minute;

  // need to adjust hour
  if (minute < 45) {
    minute = minute + 60 - 45;
    if (hour == 0) {
      hour = 23;
    }
    else {
      hour--;
    }
  }

  // don't need to adjust hour
  else {
    minute -= 45;
  }
  cout << hour << " " << minute << endl;
  return 0;
}
