#include <iostream>
#include <vector>
#include <variant>
#include <memory>

#include "coord.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"

using GeoObj = std::variant<Line, Circle, Rectangle>;

class PollObj
{
public:
	explicit PollObj() = default;
	PollObj(std::initializer_list<GeoObj>l) {
		createFigure = std::move(l);
	};
	~PollObj() = default;
	void add(const GeoObj& ob) {
		createFigure.push_back(ob);
	};
	void del(const GeoObj& ob) {
		createFigure.push_back(ob);
	};
	void draw() {
			for (const GeoObj& geoobj : createFigure) {
			std::visit([](const auto& obj) {
				obj.draw(); 
					   },
					   geoobj);
		}
	}
private:
	std::vector<GeoObj> createFigure;
};


int main() {
	// 
	PollObj	b {	Line		{Coord{1,2},Coord{3,4}},
				Circle		{Coord{5,5},2},
				Rectangle	{Coord{3,3},Coord{6,4}},
				Line		{Coord{1,2},Coord{3,4}},
				Rectangle	{Coord{3,3},Coord{6,4}}
		};
	
	b.draw();

	return 0;
}
