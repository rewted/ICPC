#include <iostream>
#include <string>

int gcd (int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);  
}

using namespace std;

int main () {
  string a;
  cin >> a;
  //cout << a << endl;
  bool first_half = true;
  string beginning;
  string end;
  for (auto x: a) {
    if (!first_half) {
      end += x;
    }
    if (x == '/') {
      first_half = false;
    }
    if (first_half) {
      beginning += x;
    }
  }
  int num = stoi(beginning);
  int dem = stoi(end);

  int b = 32;
  b *= dem;
  num -= b;
  num *= 5;
  dem *= 9;


  
  int greatest_divisor = gcd(num, dem);
  num /= greatest_divisor;
  dem/= greatest_divisor;
  if (num > 0 && dem < 0) {
    num *= -1;
    dem *= -1;
  }
  if (num < 0 && dem < 0) {
    num *= -1;
    dem *= -1;
  }
  cout << num << "/" << dem << endl;
  return 0;
}
