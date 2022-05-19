#include "view.h"
#include "iostream"


    view_project::view_project(const graph_project& _model): model{_model} {
     }

    void view_project::redraw() {
        render();
    }

    void view_project::render() {
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
    }

