#include <iostream>
#include <vector>

void find_king(std::vector<int> group) {
  int prev = group[0];
  int curr = group[1];
  for (int i = 1; i < (int)group.size()-1; i++) {
    curr = group[i];

    if (prev+1 != curr) {
      std::cout << i+1 << std::endl;
      break;
    }
    
    prev = curr;
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
    //std::cout << gnomes << " Gnoems."  << std::endl;
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
