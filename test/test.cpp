#include <iostream>

#include "../src/cell_controller.hpp"
#include "../src//window_manager.hpp"

int main() {
    while (true) {
        int w, h;
        std::cout << "width ? ";
        std::cin >> w;
        std::cout << "height ? ";
        std::cin >> h;
        WindowManager window(w, h, 10);
        std::cout << "xCellDemand: " << window.xCellDemand()
                  << ", yCellDemand: " << window.yCellDemand()
                  << "\nleftMargin: " << window.leftMargin()
                  <<", bottomMargin: " << window.bottomMargin()
                  << std::endl << std::endl;
    }
}
