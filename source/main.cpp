
#include <iostream>
#include <memory>

#include "model.h"
#include "view.h"
#include "controller.h"
#include "base_primitive.h"

int main() {
	//создаем пространство шаблона MVC
	graph_project model{};
	view_project view{ model };
	controller canvas(model, view);

	//загружаем проект
	canvas.import_project("Document");

	//Созданием и добавляем на экран примитив Line
	auto line = std::shared_ptr <base_primitive>(
		new Line{ Coord{1,2},Coord{3,4} }
	);
	canvas.add_primitive(line);
	//Созданием и добавляем на экран примитив Rectangle
	auto rectangle = std::shared_ptr <base_primitive>(
		new Rectangle{ Coord{3,3},Coord{6,4} }
	);
	canvas.add_primitive(rectangle);
	//Созданием и добавляем на экран примитив Circle
	auto circle = std::shared_ptr <base_primitive>(
		new  Circle{ Coord{5,5},2 }
	);
	canvas.add_primitive(circle);

	return 0;
}
