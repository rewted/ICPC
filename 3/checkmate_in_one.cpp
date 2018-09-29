#include <iostream>
#include <string>
#include <vector>

using namespace std;

int abs (int a) {
  if (a < 0) {
    return -a;
  }
  return a;
}

bool checkmate(vector<string> board) {
  int kx, ky, rx, ry;
  int ex, ey;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0;  j < board[i].size(); j++) {
      if (board[i][j] == 'K') {
	kx = i;
	ky = j;
      }
      if (board[i][j] == 'k') {
	ex = i;
	ey = j;
      }
      if (board[i][j] == 'R') {
	rx = i;
	ry = j;
      }
    }
  }
  // piece positions found

  // check if k is on the edge
  if ((ex == 0) || (ex == 7) || (ey == 0) || (ey == 7)) {
    // non corner case
    if (kx == ex) {
      if (abs(ky - ey) != 2) {
	return false;
      }
      if (abs(rx-ex) < 2) {
	return false;
      }
      return true;
    }

    if (ky == ey) {
      if (abs(kx - ex) != 2) {
	return false;
      }
      if (abs(ry-ey) < 2) {
	return false;
      }
      return true;
    }

    // corner case
    if ((ex == 0 && ey == 0) || (ex == 0 && ey == 7) || (ex == 7 && ey == 0) || (ex == 7 && ey == 7)) {
      if (abs(kx - ex) == 2) {
	if (abs(ky-ey) == 1) {
	  if (abs(ry - ey) < 2) {
	    return false;
	  }
	  else {
	    return true;
	  }
	}
	return false;
      }

      if (abs(ky - ey) == 2) {
	if (abs(kx - ex) == 1) {
	  if (abs(ry - ey) < 2) {
	    return false;
	  }
	  else {
	    return true;
	  }
	}
	return false;
      }
    }
    return false;

    
  }


  // not on edge
  else {
    return false;
  }
  
}

/*
bool find_own_rook(vector<string> board, int exp, int eyp, int kx, int ky) {
  int rxp;
  int ryp; 
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j <board[i].size(); j++) {
      if (board[i][j] == 'R') {
	rxp = i;
	ryp = j;

	// corner cases
	if ((exp == 0 && eyp == 0) || (exp == 0 && eyp == 7) || (exp == 7 && eyp == 0) || (exp == 7 && eyp == 7)) {
	  
	  if (abs(exp - kx) == 2) {
	    if (eyp == ky) {
	      if (ky == ryp) {
		return false;
	      }
	      if (abs(ryp - eyp) < 2) {
		return false;
	      }
	      else {
		return true;
	      }
	    }
	  }

	  if (abs(eyp - ky) == 2) {
	    if (exp == kx) {
	      if (kx == rxp) {
		return false;
	      }
	      if (abs(rxp - exp) < 2) {
		return false;
	      }
	      else {
		return true;
	      }
	    }
	  }
	}	  
      }
	
	// non corner cases
	if (exp == kx) {
	  if (rxp == kx) {
	    return false;
	  }
	  if (abs(ryp - eyp) < 2) {
	    return false;
	  }
	  else {
	    return true;
	  }
	}
	
	if (eyp == ky) {
	  if (ryp == kx) {
	    return false;
	  }
	  if (abs(rxp - exp) < 2) {
	    return false;
	  }
	  else {
	    return true;
	  }
	}
      }
    }
  return false;
}

bool find_own_king(vector<string> board, int e_x_pos, int e_y_pos) {
  int K_x_pos;
  int K_y_pos;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == 'K') {
	K_x_pos = i;
	K_y_pos = j;
	//cout << "K: " << K_x_pos << " " << K_y_pos << endl;
	
	// corner case
	if ((e_x_pos == 0 && e_y_pos == 0) || (e_x_pos == 0 && e_y_pos == 7) || (e_x_pos == 7 && e_y_pos == 0) || (e_x_pos == 7 && e_y_pos == 7)) {
	  if ((e_x_pos == K_x_pos) || (abs(e_x_pos - K_x_pos) == 1)) {
	    if (abs(e_y_pos - K_y_pos) == 2) {
	      return find_own_rook(board, e_x_pos, e_y_pos, K_x_pos, K_y_pos);
	      // in corner in positionc check rook
	      //cout << "in corner in position" << endl;
	    }

	  }
	  if ((e_y_pos == K_y_pos) || (abs(e_y_pos - K_y_pos) == 1)) {
	    if (abs(e_x_pos - K_x_pos) == 2) {
	      return find_own_rook(board, e_x_pos, e_y_pos, K_x_pos, K_y_pos);
	      // in corner in position check rook
	      //cout << "in corner in position y" << endl;
	    }

	  }
	}


	
	// on edge need to be on same row or same column
	if ((e_x_pos == K_x_pos) || (e_y_pos == K_y_pos)) {
	  // x pos same
	  if (e_x_pos == K_x_pos) {
	    if (abs(e_y_pos - K_y_pos) == 2) {
	      // check for rook
	      return find_own_rook(board, e_x_pos, e_y_pos, K_x_pos, K_y_pos);
	      //cout << "In position x same" << endl;
	    }
	  }
	  // y pos same
	  if (e_y_pos == K_y_pos) {
	    if (abs(e_x_pos - K_x_pos) == 2) {
	      // check for rook
	      return find_own_rook(board, e_x_pos, e_y_pos, K_x_pos, K_y_pos);
	      //cout << "In position y same" << endl;
	    }
	  }
	}
      }
    }
  }
  return false;
}

bool king_on_edge(vector<string> board) {
  int x_pos;
  int y_pos;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == 'k') {
	x_pos = i;
	y_pos = j;
	
	//cout << "enemy king on " << i << " " << j << endl;
	if (x_pos == 0 || x_pos == 7 || y_pos == 0 || y_pos == 7) {
	  //cout << x_pos << " " << y_pos << endl;
	  return find_own_king(board, x_pos, y_pos);
	}
	else {
	  return false;
	}
      }
    }
  }
  return false;
}
*/

int main () {
  int rows = 8;
  vector<string> board;
  string tempstr;
  for (int i = 0; i < rows; i++) {
    cin >> tempstr;
    board.push_back(tempstr);
  }
  /*
  for (int i = 0; i < rows; i++) {
    for (auto x : board[i]) {
      cout << x;
    }
    cout << endl;
  }
  */
  if(!checkmate(board)) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  return 0;
}
