#include <iostream>
#include <vector>
#include <cmath>

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
  for (int i = 0; i < number_of_points; i++) {
    for (int j = i+1; j < number_of_points; j++) {
      int dx = abs(all_points[i].x - all_points[j].x);
      int dy = abs(all_points[i].y - all_points[j].y);
      if ((dx <= 2018) && (dy <= 2018)) {
	if (dx * dx + dy * dy ==  4072324) {
	  //cout << all_points[i].x << " " << all_points[i].y << endl;
	  //cout << all_points[j].x << " " << all_points[j].y << endl;
	  points_2018++;
	}
	else {
	  //cout << dx << " " << dy << " " << dx * dx + dy * dy << endl;
	  //cout << "Fail distance" << endl;
	}
      }
      else {
	//cout << "Fail delta " << dx << " " << dy << endl;
      }
    }
  }
  cout << points_2018 << endl;
    /*for (auto x: all_points) {
    cout << x.x << " " << x.y << endl;
  }
  */
  return 0;
}
