#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int distance_formula (int a, int b) {
  int asq = a * a;
  int bsq = b * b;
  return sqrt (asq + bsq);
}

int points_scored (double radius) {
  int p = 11;
  if (radius <= 20) {
    p = 1;
  }
  else if (radius <= 40) {
    p = 2;
  }
  else if (radius <= 60) {
    p = 3;
  }
  else if (radius <= 80) {
    p = 4;
  }
  else if (radius <= 100) {
    p = 5;
  }
  else if (radius <= 120) {
    p = 6;
  }
  else if (radius <= 140) {
    p = 7;
  }
  else if (radius <= 160) {
    p = 8;
  }
  else if (radius <= 180) {
    p = 9;
  }
  else if (radius <= 200) {
    p = 10;
  }
  else {
    return 0;
  }
  return (11 - p); 
}

int main () {
  std::ifstream is("in2.txt");
  std::string line;
  int cases = 0;
  int throws = 0;
  int score = 0;
  int xd = 0;
  int yd = 0;
  double distance = 0;
  std::string temp;
  if (is.is_open()) {
    getline (is, line);
    cases = stoi(line);
    while (getline (is, line)) {
      if (cases == 0) {
	break;
      }
      if (throws == 0) {

	score = 0;
	throws = stoi(line);
      }
      else {
	throws--;
	if (throws == 0) {
	  std::cout << score << std::endl;
	  cases--;
	}
	int pos = 0;
	for (auto x : line) {
	  if (x == ' ') {
	    //std::cout << pos << std::endl;
	    break;
	  }
	  pos++;
	}
	//std::cout << stoi(line.substr(0, pos)) << " ";
	//std::cout << stoi(line.substr(pos, line.size())) << std::endl;
	xd = stoi(line.substr(0, pos));
	yd = stoi(line.substr(pos, line.size()));
	distance = distance_formula(xd, yd);
	score += points_scored(distance);
	
      }
      //std::cout << line << std::endl;
    }
  }
  //std::cout << cases << std::endl;
  return 0;
}
