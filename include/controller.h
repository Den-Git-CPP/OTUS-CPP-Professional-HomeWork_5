#pragma once

#include <string>
#include "model.h"
#include "view.h"


class controller {
public:
	/**
	 * @brief Конструктор контролера
	 * 
	 * @param model ссылка на класс graph_project 
	 * @param view ссылка на класс view_project
	 */
	controller(graph_project& model, view_project& view);

	/**
	 * @brief Загрузка проекта и отрисовка
	 * 
	 * @param path путь до файла
	 */
	void import_project(const std::string& path);

		/**
	 * @brief Сохранение проекта 
	 * 
	 * @param path путь до файла
	 */
	void export_project(const std::string& path);

	/**
	 * @brief Добавление и сохранение примитива 
	 * 
	 * @param primitive ссылка  "умный указатель" на примитив фигуры
	 */
	void add_primitive(std::shared_ptr<base_primitive>& primitive);

	/**
	 * @brief Удаление примитива 
	 * 
	 * @param primitive ссылка  "умный указатель" на примитив фигуры
	 */
	void remove_primitive(std::shared_ptr <base_primitive>& primitive);

private:
	graph_project& _model;
	view_project _view;
};

