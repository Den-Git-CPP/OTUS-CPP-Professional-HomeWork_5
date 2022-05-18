#pragma once
#include <iostream>
#include "coord.h"

class Circle {
  public:
    Circle (Coord c, int r)
     : center{c}, rad{r} {
    }
	void move(const Coord& c) {
      center += c;
    }
	void draw() const {
      std::cout << "CIRCLE at " << center
                << " with radius " << rad << '\n';
    }
  
   private:
    Coord center;
    int rad;
};



