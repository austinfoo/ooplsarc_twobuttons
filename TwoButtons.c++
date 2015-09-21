// ----------------------------
// projects/twobuttons/Twobuttons.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <queue>
#include <utility>

#include "Twobuttons.h"

using namespace std;

// ------------
// twobuttons_read
// ------------

Entry twobuttons_read (const std::string& s) {
  std::istringstream sin(s);
  int n = 0;
  int m = 0;
  sin >> n >> m;
  return std::make_pair(n, m);
}

// ------------
// twobuttons_eval
// ------------

int twobuttons_eval (int n, int m)
{
  std::queue<Entry> q;

  q.push(std::make_pair(n, 0));

  while (!q.empty()) {

    const Entry val = q.front();
    q.pop();

    // Check for termination condition
    if (val.first == m) {
      return val.second;
    }

    // Red button - double
    int red_val = 2 * val.first;
    int red_count = val.second + 1;
    Entry red_node (red_val, red_count);
    q.push(red_node);
    
    // Blue button - subtract one
    int blue_val = val.first - 1;
    if (blue_val >= 0) {
      int blue_count = val.second + 1;
      Entry blue_node (blue_val, blue_count);
      q.push(blue_node);
    }

    // if new val is greater than m then don't push new red val
    // keep array of vals visited and don't push matches

  }

  assert (false);
  return 0;
}

// -------------
// twobuttons_print
// -------------

void twobuttons_print (ostream& w, const int answer) {
  w << answer << std::endl;
}

// -------------
// twobuttons_solve
// -------------

void twobuttons_solve (istream& r, ostream& w) {
  std::string s;
  while (getline(r, s)) {
    const Entry val = twobuttons_read(s);
    const int answer = twobuttons_eval(val.first, val.second);
    twobuttons_print(w, answer);
  }
}
