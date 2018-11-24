#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string encode(string s) {
  if ((int)s.length() < 1) {
    return s;
  }
  int count = 1;
  char c = *(s.begin());
  string temp;
  string::iterator s_itr = s.begin();

  while (s_itr != s.end()) {
    s_itr++;
    if (c == *s_itr) {
      count++;
    }
    else {
      if (count > 1) {
	temp.append(to_string(count));
	temp.push_back(c);
	count = 1;
	c = *s_itr;
      }
      else {
	temp.push_back(c);
	c = *s_itr;
      }
    }
  }
  
  
  return temp;
}

int main () {
  string s;
  cin >> s;

  cout << encode(s) << endl;
  
  return 0;
}
