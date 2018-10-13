#include <iostream>

using namespace std;

struct point {
  int x;
  int y;
}point;

int main () {
  struct point p1, p2, p3, p4;

  cin >> p1.x >> p1.y;
  cin >> p2.x >> p2.y;
  cin >> p3.x >> p3.y;

  if (p1.x == p2.x) {
    p4.x = p3.x;
  }
  if (p1.x == p3.x) {
    p4.x = p2.x;
  }
  if (p2.x == p3.x) {
    p4.x = p1.x;
  }

  if (p1.y == p2.y) {
    p4.y = p3.y;
  }
  if (p1.y == p3.y) {
    p4.y = p2.y;
  }
  if (p2.y == p3.y) {
    p4.y = p1.y;
  }

  cout << p4.x << " " << p4.y << endl;
  
  return 0;
}
