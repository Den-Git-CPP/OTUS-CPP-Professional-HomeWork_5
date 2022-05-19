#pragma once

#include "model.h"


class view_project {
public:
	/**
	 * @brief Конструктор для View в модели MVC
	 * 
	 * @param Ссылка на класс graph_project
	 */
	explicit view_project(const graph_project& _model);

	/**
	 * @brief Функция прорисовки если есть данные
	 * 
	 */
	void redraw();

private:
	const graph_project& model;
	
	/**
	 * @brief Функция показа текщей модели
	 * 
	 */
	void render();
};
