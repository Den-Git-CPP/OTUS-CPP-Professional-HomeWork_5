#include "controller.h"


controller::controller(graph_project& model, view_project& view) :
	_model{ model }, _view{ view } {
}

void controller::import_project(const std::string& path) {
	_model.load_project(path);
	_view.redraw();
}

void controller::export_project(const std::string& path) {
	_model.save_project(path);
}

void controller::add_primitive(std::shared_ptr <base_primitive>& primitive) {
	_model.add_primitive_to_project(primitive);
	_view.redraw(); // notify view to update canvas
}

void controller::remove_primitive(std::shared_ptr  <base_primitive>& primitive) {
	_model.remove_primitive_from_project(primitive);
	_view.redraw(); // notify view to update canvas
}


