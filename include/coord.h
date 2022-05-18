#pragma once
#include <iostream>

class Coord {
  public:
    Coord() : x{0}, y{0} {}
    Coord(int newx, int newy) 
    : x{newx}, y{newy} 
    {}

    Coord operator- () const {                   
      return Coord{-x, -y};
    }
    void operator+= (Coord c) {                  
      *this = *this + c;
    }
    void operator-= (Coord c) {                   
      operator+=(-c); 
    }

    int getX() const {
      return x;
      }
    int getY() const {
      return y;
      }
    
    friend Coord operator+ (Coord c1, Coord c2) {
      return Coord{c1.x+c2.x, c1.y+c2.y};
    }
    friend Coord operator- (Coord c1, Coord c2) {
      return Coord{c1.x-c2.x, c1.y-c2.y};
    }
    
    friend std::ostream& operator<< (std::ostream& strm, Coord c) {
      return strm << '(' << c.x << ',' << c.y << ')';
    }
  
    private:
    int x;  
    int y;  
};



