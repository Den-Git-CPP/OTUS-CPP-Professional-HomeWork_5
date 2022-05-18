#pragma once
#include <iostream>
#include "coord.h"

class Line {
  public:
    Line (Coord f, Coord t)
     : from{f}, to{t} {
    }

    void move(const Coord& c) {
      from += c;
      to += c;
    }

    void draw() const {
      std::cout << "LINE from " << from
                << " to " << to << '\n';
    }
  private:
    Coord from;
    Coord to;
};
