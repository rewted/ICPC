#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



struct points{
  long int x;
  long int y;
}points;

int main () {
  int number_of_points = 0;
  cin >> number_of_points;
  vector<struct points> all_points {};
  struct points temp;
  for (int i = 0; i < number_of_points; i++) {
    cin >> temp.x;
    cin >> temp.y;
    all_points.push_back(temp);
  }

  int points_2018 = 0;
  /*
  sort(all_points.begin(), all_points.end(), [](struct points a, struct points b) {
      return a.x < b.x;

    });
  */
  for (int i = 0; i < number_of_points; i++) {
    for (int j = i+1; j < number_of_points; j++) {
      int dx = abs(all_points[i].x - all_points[j].x);
      if (dx <= 2018) {
	int dy = abs(all_points[i].y - all_points[j].y);
	if (dy <= 2018) {
	  if (dx * dx + dy * dy ==  4072324) {
	    //cout << all_points[i].x << " " << all_points[i].y << endl;
	    //cout << all_points[j].x << " " << all_points[j].y << endl;
	    points_2018++;
	  }
	}
      }
      /*
      else {
	break;
      }
      */
      
    }
  }
  cout << points_2018 << endl;
    /*for (auto x: all_points) {
    cout << x.x << " " << x.y << endl;
  }
  */
  return 0;
}
