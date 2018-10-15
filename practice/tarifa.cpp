#include <iostream>

using namespace std;

int main () {
  int monthly_bandwidth;
  int number_of_months;

  cin >> monthly_bandwidth;
  cin >> number_of_months;
  
  int total_hours = monthly_bandwidth * (number_of_months+1);

  int usage;

  for (int i = 0; i < number_of_months; i++) {
    cin >> usage;
    total_hours -= usage;
  }
  cout << total_hours << endl;
  return 0;
}
