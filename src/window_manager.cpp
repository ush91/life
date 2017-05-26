#include "window_manager.hpp"

WindowManager::WindowManager(int w, int h, int c_s) {
    width = w;
    height = h;
    cell_size = c_s;
    x_is_even = ((width / cell_size) % 2 == 0);
    y_is_even = ((height / cell_size) % 2 == 0);
}

void WindowManager::resize(int w, int h) {
    width = w;
    height = h;
}

int WindowManager::xCellDemand() {
    if (x_is_even) {
        return (width + 2 * cell_size - 1) / (2 * cell_size) * 2;
    } else {
        return (width + cell_size - 1) / (2 * cell_size) * 2 + 1;
    }
}

int WindowManager::yCellDemand() {
    if (y_is_even) {
        return (height + 2 * cell_size - 1) / (2 * cell_size) * 2;
    } else {
        return (height + cell_size - 1) / (2 * cell_size) * 2 + 1;
    }
}

int WindowManager::leftMargin() {
    int remain_width = (x_is_even
                        ? width % (2 * cell_size)
                        : (width + cell_size) % (2 * cell_size));
    return remain_width == 0 ? 0 : (remain_width + 1) / 2 - cell_size;
    //    return (width % (2 * cell_size) + 1) / 2;
}

int WindowManager::bottomMargin() {
    int remain_height = (y_is_even
                         ? height % (2 * cell_size)
                         : (height + cell_size) % (2 * cell_size));
    return remain_height == 0 ? 0 : (remain_height + 1) / 2 - cell_size;
}

// int WindowManager::xCellStart(int x_cell) {
//     if (x_cell % 2 == 0) {
//         return (x_cell - (width + 2 * cell_size - 1) / (2 * cell_size) * 2) / 2;
//     } else {
//         return (x_cell - 1 - (width + cell_size - 1) / (2 * cell_size) * 2) / 2;
//     }
//     // int full_size_cell = (x_is_even
//     //                       ? window_w / (2 * cell_w)
//     //                       : (window_w - cell_w) / (2 * cell_w) + 1);
//     // int left_width = width - cell_size * full_size_cell;
//     // if (left_width < 2) {
//     //     // 0 OR 1
//     //     return (x_cell - full_size_cell) / 2;
//     // } else {
//     //     return (x_cell - full_size_cell - 2) / 2;
//     // }
// }

// int WindowManager::yCellStart(int y_cell) {
//     if (y_cell % 2 == 0) {
//         return (y_cell - (height + 2 * cell_size - 1) / (2 * cell_size) * 2) / 2;
//     } else {
//         return (y_cell - (height + 2 * cell_size - 1) / (2 * cell_size) * 2) / 2;
//     }
//     // int full_size_cell = (y_cell_is_even
//     //                       ? window_h / (2 * cell_h)
//     //                       : (window_h - cell_h) / (2 * cell_h) + 1);
//     // int bottom_height = window_h - cell_h * full_size_cell;
//     // return (bottom_height < 2
//     //         ? (y_cell - full_size_cell) / 2
//     //         : (y_cell - full_size_cell - 2) / 2);
// }
