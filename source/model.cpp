#include <algorithm>
#include <iostream>
#include <sstream>
#include "model.h"


graph_project::graph_project(const std::string& path) {
	load_project(path);
}

void graph_project::load_project(const std::string& path) {
	elements.clear();
}

void graph_project::add_primitive_to_project(std::shared_ptr<base_primitive>& primitive) {
	elements.emplace_back(primitive);
}

void graph_project::remove_primitive_from_project(std::shared_ptr<base_primitive>& primitive) {
	auto position = std::find(elements.begin(), elements.end(), primitive);
	if (position != elements.end()) {
		elements.erase(position);
	}
}

void graph_project::save_project(const std::string& path) {
	for (const auto& element : elements) {
	}
}

std::vector<std::string> graph_project::get_elements_redrawing() const {
	std::vector<std::string> redrawing;

	for (const auto& element : elements) {
		redrawing.emplace_back(element->draw_figure().c_str());
	}

	return redrawing;
}

