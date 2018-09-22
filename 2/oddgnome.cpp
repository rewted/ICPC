#include <iostream>
#include <vector>

void find_king(std::vector<int> group) {
  /*
  auto gnomes_group_itr = group.begin();
  while (gnomes_group_itr != group.end()) {
    std::cout << *gnomes_group_itr << std::endl;
    gnomes_group_itr++;
  }
  */
  for (int i = 1; i < (int)group.size(); i++) {
    if (group[i] < group[i-1] && group[i] < group[i+1]) {
      //std::cout << group[i] << " " << i+1 << std::endl;
      break;
    }
    if (group[i] > group[i+1] && group[i] > group[i-1]) {
      if (i < (int)group.size()-2) {
	if (group[i] < group[i+2]) {
	  std::cout << i+2 << std::endl;
	  break;
	}
      }
      //std::cout << group[i] << " " << i+1 << std::endl;
      std::cout << i+1 << std::endl;
      break;
    }
  }
}

void get_gnomes (int gnome_count) {
  //std::cout << "Number of gnomes: " << gnome_count << std::endl;
  std::vector<int> gnomes_order {};
  int temp = 0;
  for (int i = 0; i < gnome_count; i++) {
    std::cin >> temp;
    gnomes_order.push_back(temp);
  }
  find_king(gnomes_order);

}



int main () {
  int groups = 0;
  // number of groups of gnomes
  std::cin >> groups;
  int gnomes = 0;
  for (int i = 0; i < groups; i++) {
    // number of gnomes in the group
    std::cin >> gnomes;
    get_gnomes(gnomes);
    

    //gnomes_order.clear();
    //int temp = 0;
    //not_found = true;
    /*
    for (int j = 0; j < gnomes; j++) {
      std::cin >> temp;
      if(not_found) {
	if (gnomes_order.size() > 0) {
	  if (gnomes_order[gnomes_order.size()-1] > temp) {
	    std::cout << temp;
	    not_found = false;
	  }
	}
      }
      gnomes_order.push_back(temp);
    }
    */
    
  }
  return 0;
}
