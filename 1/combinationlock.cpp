#include <iostream>
#include <string>
#include <fstream>

int find_degrees(int d) {
  return d * 9;
}

int find_distance_clock(int pos, int dest) {
  if (pos <= dest) {
    return pos + 40 - dest;
  }
  else {
    return pos - dest;
  }
}

int find_distance_ccw(int pos, int dest) {
  if(pos >= dest) {
    return 40 + dest - pos;
  }
  else {
    return pos - dest;
  }
}

int main () {
  std::string line;
  std::ifstream is("combo.txt");


  while (getline (is, line)) {
    auto it = line.begin();
    int degrees_traveled = 1080;
    int count = 0;
    int space_pos1 = 0;
    int space_pos2 = 0;
    int space_pos3 = 0;
    int init_pos = -1;
    int comb1 = -1;
    int comb2 = -1;
    int comb3 = -1;
    int dist_traveled = 0;
    // parse the line
    for (auto x : line) {
      if (x == ' ') {
	if (init_pos == -1) {
	  init_pos = std::stoi(line.substr(0, count));
	  //std::cout << init_pos << std::endl;
	  space_pos1 = count;
	}
	else if (comb1 == -1){
	  comb1 = std::stoi(line.substr(space_pos1, count));
	  //std::cout << comb1 << std::endl;
	  space_pos2 = count;
	}
	else if (comb2 == -1) {
	  comb2 = std::stoi(line.substr(space_pos2, count));
	  //std::cout << comb2 << std::endl;
	  space_pos3 = count;
	  comb3 = std::stoi(line.substr(space_pos3, count));
	  //std::cout << comb3 << std::endl;
	  break;
	}
      }
      count++;
    }
    // read all four zeros
    if (init_pos == 0 && comb1 == 0 && comb2 == 0 && comb3 == 0) {
      break;
    }
    // perform calculation
    dist_traveled += find_distance_clock(init_pos, comb1);
    dist_traveled += find_distance_ccw(comb1, comb2);
    dist_traveled += find_distance_clock(comb2, comb3);
    degrees_traveled += dist_traveled * 9;
    std::cout << degrees_traveled << std::endl;
    //std::cout << "Deg: " << degrees_traveled << " Dist: " << dist_traveled << std::endl;
    /*
    std::cout << find_distance_clock(init_pos, comb1) << std::endl;
    std::cout << find_distance_ccw(comb1, comb2) << std::endl;
    std::cout << find_distance_clock(comb2, comb3) << std::endl;
    std::cout << "--------" << std::endl;
    */
    //std::cout << line << std::endl;
    
  }
  return 0;
}
