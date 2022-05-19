#pragma once

#include <string>
#include <vector>
#include <memory>
#include "base_primitive.h"


class graph_project {
public:
	/**
	 * @brief Конструктор пустого проекта
	 * 
	 */
	graph_project() = default;

	/**
	 * @brief Конструктор проекта с загрузкой файла
	 * 
	 * @param path путь к файлу проекта
	 */
	graph_project(const std::string& path);

	/**
	 * @brief Функция загрузки проекта из файла
	 * 
	 * @param path путь к файлу проекта
	 */
	void load_project(const std::string& path);

	/**
	 * @brief Функция добавления примитива в проект
	 * 
	 * @param умный указатель на примитив
	 */
	void add_primitive_to_project(std::shared_ptr<base_primitive>& primitive);
	/**
	 * @brief Функция удаления примитива из проекта
	 * 
	 * @param умный указатель на примитив
	 */
	void remove_primitive_from_project(std::shared_ptr<base_primitive>& primitive);
	/**
	 * @brief Функция сохранения проекта в файл
	 * 
	 * @param path путь к файлу проекта
	 */
	void save_project(const std::string& path);

	std::vector<std::string> get_elements_redrawing() const;

private:
/**
 * @brief Вектор указателей на набор созданных примитивов в проекте
 * 
 */
	std::vector<std::shared_ptr <base_primitive>> elements; 
};

