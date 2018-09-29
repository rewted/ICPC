#include <iostream>
#include <unordered_map>
#include <string>

int min (int a, int b) {
  if (a <= b) {
    return a;
  }
  return b;
}

using namespace std;

int main () {
  int submissions;
  cin >> submissions;

  unordered_map<string, int> domjudge;
  unordered_map<string, int> kattis;
  string temp;
  for (int i = 0; i < submissions; i++) {
    cin >> temp;
    if (domjudge.find(temp) == domjudge.end()) {
      domjudge.insert({temp, 1});
    }
    else {
      domjudge[temp]++;
    }
  }

  for (int i = 0; i < submissions; i++) {
    cin >> temp;
    if (kattis.find(temp) == kattis.end()) {
      kattis.insert({temp, 1});
    }
    else {
      kattis[temp]++;
    }
  }
  //cout << kattis.size() << " " << domjudge.size() << endl;

  int tmp;
  int total = 0;
  if (kattis.size () >= domjudge.size()) {
    for (auto x : kattis) {
      tmp = min(kattis[x.first], domjudge[x.first]);
      total += tmp;
    }
  }
  else {
    for (auto x : domjudge) {
      tmp = min(kattis[x.first], domjudge[x.first]);
      total += tmp;
    }
  }

  cout << total << endl;
  /*
  for (auto x : domjudge) {
    cout << x.first << " " << x.second << endl;
  }
  */
  return 0;
}
