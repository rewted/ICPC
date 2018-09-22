#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void get_data(int count, vector<int> * data) {
  int temp = 0;
  for (int i = 0; i < count; i++) {
    cin >> temp;
    data->push_back(temp);
  }
  sort(data->begin(), data->end());
}

void print_data (vector<int> * data) {
  auto itr = data->begin();
  while (itr != data->end()) {
    cout << *itr << endl;
    itr++;
  }
}

double find_hypot (int a) {
  double length = (double)a/2;
  return sqrt(length*length + length*length);
}

int plots_filled_with_houses(vector<int> * plots, vector<int> * circles, vector<int> * squares) {
  int plots_filled = 0;
  auto plots_itr = plots->begin();
  auto circles_itr = circles->begin();
  auto squares_itr = squares->begin();
  while (plots_itr != plots->end()) {
    // does house fit in plot?
    if (*circles_itr < *plots_itr) {
      plots_filled++;
      circles_itr++;
    }
    else {
      if (find_hypot(*squares_itr) < *plots_itr) {
	plots_filled++;
	squares_itr++;
      }
    }
    plots_itr++;
  }

  return plots_filled;
}

int main () {
  int plots = 0;
  int circle_homes = 0;
  int square_homes = 0;

  vector<int> plots_radius {};
  vector<int> circle_homes_radius {};
  vector<int> square_homes_side {};
  
  cin >> plots;
  cin >> circle_homes;
  cin >> square_homes;

  get_data(plots, &plots_radius);
  get_data(circle_homes, &circle_homes_radius);
  get_data(square_homes, &square_homes_side);

  cout << plots_filled_with_houses(&plots_radius, &circle_homes_radius, &square_homes_side) << endl;

  return 0;
}
