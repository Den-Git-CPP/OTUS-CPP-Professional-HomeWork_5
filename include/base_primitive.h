#pragma once
#include <iostream>
#include <sstream>
#include <string>

/*! \mainpage OTUS-CPP-Professional-HomeWork_5 (Графический редактор)
 *
 *  \n   Макеты классов для простейшего векторного редактора
 *
 */
#pragma region Coord
class Coord {
public:
/**
* @brief конструктор для класса с координатами 0,0
* 
*/
	Coord() : x{ 0 }, y{ 0 } {}
/**
 * @brief конструктор для класса с переданными координатами
 * 
 * @param newx 
 * @param newy 
 */
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
/**
 * @brief Базовый класс для всех фигур
 * 
 */
class base_primitive {
public:

	virtual ~base_primitive() {};
	virtual void move_figure(const Coord& c) = 0;
	virtual std::string draw_figure() = 0;

};

#pragma region Line
/**
 * @brief Класс представляющий Линию
 * 
 */
class Line :public base_primitive {
public:
/**
 * @brief Конструктор обьекта Линии
 * 
 * @param f координата начала линии
 * @param t координата конца линии
 */
	Line(Coord f, Coord t) :
		from{ f }, to{ t } {
	}
	/**
	 * @brief Деструткор
	 * 
	 */
	~Line() override {};
	/**
	 * @brief Функция изменения координат объекта
	 * @param c сслыка на обект Coord соодержащий координаты
	 */
	void move_figure(const Coord& c) {
		from += c;
		to += c;
	}
	/**
 	* @brief Функция прорисовки линии
	* @return std::string возвращает сообщение о прорисовки
	 */
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

#pragma region Circle/**
 * @brief Класс представляющий Окружность
 * 
 */
class Circle :public base_primitive {
public:
/**
 * @brief Конструктор обьекта Окружность
 * 
 * @param c сслыка на обект Coord соодержащий координаты
 * @param r радиус окружности
 */
	Circle(Coord c, int r) :
		center{ c }, rad{ r } {
	}
	~Circle() override {};
	/**
	 * @brief Функция изменения координат объекта
	 * @param c сслыка на обект Coord соодержащий координаты
	 */
	void move_figure(const Coord& c) {
		center += c;
	}
	/**
 	* @brief Функция прорисовки окружности
	* @return std::string возвращает сообщение о прорисовки
	 */
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
/**
 * @brief Класс представляющий  прямоугольник
 * 
 */
class Rectangle :public base_primitive {
public:
/**
 * @brief Конструктор обьекта Прямоугольник
 * 
 * @param f  координата угла для прорисовки прямоугольника
 * @param t  координата угла для прорисовки прямоугольника
 */
	Rectangle(Coord f, Coord t) :
		from{ f }, to{ t } {
	}
	~Rectangle() override {};
	/**
	 * @brief Функция изменения координат объекта
	 * @param c сслыка на обект Coord соодержащий координаты
	 */
	void move_figure(const Coord& c) {
		from += c;
		to += c;
	}
	/**
 	* @brief Функция прорисовки прямоугольника
	* @return std::string возвращает сообщение о прорисовки
	 */
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

