
#ifndef Kitayuta_h
#define Kitayuta_h

// --------
// includes
// --------

#include <iostream>
#include <string>

using namespace std;

// ------------
// kitayuta_read
// ------------

/**
 * read a string
 * @param s a string
 * @return the input string
 */
std::string kitayuta_read (const string& s);

// ------------
// kitayuta_eval
// ------------

/**
 * @param s the input string
 * @return the answer
 */
std::string kitayuta_eval (const std::string& s);

// -------------
// kitayuta_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param out the answer
 */
void kitayuta_print (ostream& w, const std::string& out);

// -------------
// kitayuta_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void kitayuta_solve (istream& r, ostream& w);

#endif
// ----------------------------
// projects/kitayuta/Kitayuta.c++
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
#include <utility>  // make_pair, pair
#include <vector>



using namespace std;

// ------------
// kitayuta_read
// ------------

std::string kitayuta_read (const std::string& s) {
  std::istringstream sin(s);
  std::string in;
  sin >> in;
  return in;
}

// ------------
// kitayuta_eval
// ------------

bool is_palindrome (int b, int r, const std::string& s)
{
  while (b < r) {
    if (s[b] != s[r]) return false;
    ++b;
    --r;
  }
  return true;
}

std::string kitayuta_eval (const std::string& s)
{
  std::string str (s);
  int b = 0;
  int r = str.size() - 1;

  while (b < r)  {
    
    if (str[b] != str[r]) {
      // Can I insert a char from the back to the front
      if (is_palindrome(b, r-1, str)) {
	str.insert(str.begin()+b, str[r]);

      } 
      // Can I insert a char from the front to the back
      else if (is_palindrome(b+1, r, str)) {
	str.insert(str.begin()+r+1, str[b]);
      }
      else {
	str = "NA";
      }
      return str;
    }
   
    ++b;
    --r;
  }

  // The input was a palindrome.  If the string was odd, then b and r point to same char.
  // Insert *b in front of b to maintain the palindrome.  If the string was even, then b
  // is one past r.  Insert and char in front of b to maintain the palindrome.  
  str.insert(str.begin()+b, str[b]);
  return str;
}

// -------------
// kitayuta_print
// -------------

void kitayuta_print (ostream& w, const std::string& out) {
  w << out << std::endl;
}

// -------------
// kitayuta_solve
// -------------

void kitayuta_solve (istream& r, ostream& w) {
  std::string s;
  while (getline(r, s)) {
    const std::string in = kitayuta_read(s);
    const std::string out = kitayuta_eval(in);
    kitayuta_print(w, out);
  }
}

#include <iostream>



// ----
// main
// ----

int main () {
    using namespace std;
    kitayuta_solve(cin, cout);
    return 0;
}
