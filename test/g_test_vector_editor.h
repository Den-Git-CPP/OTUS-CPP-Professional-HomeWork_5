#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

#pragma region Coord
class Coord {
public:
	Coord() : x{ 0 }, y{ 0 } {}
	Coord(int newx, int newy)
		: x{ newx }, y{ newy }
	{}

	Coord operator- () const {
		return Coord{ -x, -y };
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
		return Coord{ c1.x + c2.x, c1.y + c2.y };
	}
	friend Coord operator- (Coord c1, Coord c2) {
		return Coord{ c1.x - c2.x, c1.y - c2.y };
	}

	friend std::ostream& operator<< (std::ostream& strm, Coord c) {
		return strm << '(' << c.x << ',' << c.y << ')';
	}

private:
	int x;
	int y;
};
#pragma endregion
class base_primitive {
public:

	virtual ~base_primitive() {};
	virtual void move_figure(const Coord& c) = 0;
	virtual std::string draw_figure() = 0;

};

#pragma region Line
class Line :public base_primitive {
public:
	Line(Coord f, Coord t) :
		from{ f }, to{ t } {
	}
	~Line() override {};
	void move_figure(const Coord& c) {
		from += c;
		to += c;
	}
	std::string draw_figure() override {
		std::stringstream ss;
		ss << "LINE from " << from << " to " << to;
		return ss.str();
	};

private:
	Coord from;	 
	Coord to;	 
};
#pragma endregion

#pragma region Circle
class Circle :public base_primitive {
public:
	Circle(Coord c, int r) :
		center{ c }, rad{ r } {
	}
	~Circle() override {};
	void move_figure(const Coord& c) {
		center += c;
	}
	std::string draw_figure() override {
		std::stringstream ss;
		ss << "CIRCLE at " << center << " with radius " << rad;
		return ss.str();
	};

private:
	Coord center;
	int rad;
};

#pragma endregion

#pragma region Rectangle
class Rectangle :public base_primitive {
public:
	Rectangle(Coord f, Coord t) :
		from{ f }, to{ t } {
	}
	~Rectangle() override {};
	void move_figure(const Coord& c) {
		from += c;
		to += c;
	}

	std::string draw_figure() override {
		std::stringstream ss;
		ss << "RECTANGLE from " << from << " to " << to;
		return ss.str();
	};
private:
	Coord from;
	Coord to;
};
#pragma endregion

class graph_project {
public:
	graph_project() = default;
    graph_project(const std::string& path) {
	load_project(path);
    }
	void load_project(const std::string& path) {
	elements.clear();
    };
	void add_primitive_to_project(std::shared_ptr<base_primitive>& primitive) {
	elements.emplace_back(primitive);
    };  
	void remove_primitive_from_project(std::shared_ptr<base_primitive>& primitive) {
	auto position = std::find(elements.begin(), elements.end(), primitive);
	if (position != elements.end()) {
		elements.erase(position);
	}
    };
	void save_project(const std::string& path) {
	for (const auto& element : elements) {}
    };

	std::vector<std::string> get_elements_redrawing() const {

		std::vector<std::string> redrawing;
		for (const auto& element : elements) {
		redrawing.emplace_back(element->draw_figure().c_str());
			}
		return redrawing;
	};

	std::vector<std::shared_ptr <base_primitive>> elements; 
};

class view_project {
public:
    explicit view_project(const graph_project& _model): model{_model} {
     }
	void redraw() {
        render();
    };
	void render() {
        std::cout << "-------------------------------\n";
        const auto& redrawing = model.get_elements_redrawing();
        if (redrawing.empty()){
            std::cout << "EMPTY WINDOW" << std::endl;// загружаем чистый проект
        }else {
             for (auto& representation : model.get_elements_redrawing()) {
                std::cout << "*"<<representation << "\n" ;//перерисовываем каждую фигуру
             }  
        }
        std::cout << "-------------------------------\n\n\n";
    };

const graph_project& model;
};

class controller {
public:	
	controller(graph_project& model, view_project& view) :
	_model{ model }, _view{ view }{}

	void import_project(const std::string& path) {
	_model.load_project(path);
	_view.redraw();
    }
	void export_project(const std::string& path) {
	_model.save_project(path);
    }
	void add_primitive(std::shared_ptr <base_primitive>& primitive) {
	_model.add_primitive_to_project(primitive);
	_view.redraw(); // notify view to update canvas
    }
	void remove_primitive(std::shared_ptr  <base_primitive>& primitive) {
	_model.remove_primitive_from_project(primitive);
	_view.redraw(); // notify view to update canvas
    }

	graph_project& _model;
	view_project _view;
};


