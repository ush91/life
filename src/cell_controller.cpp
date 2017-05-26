#include <queue>
#include "cell_controller.hpp"

static constexpr int born[] = {3};
static constexpr int survive[] = {2, 3};

static std::deque<std::deque<bool>> cell_alive;

void expandWorld(int x, int y) {
    if (cell_alive.front().size() < x) {
        while (cell_alive.front().size() < x) {
            for (auto&& e : cell_alive) {
                e.push_front(false);
                e.push_back(false);
            }
        }
    }

    if (cell_alive.size() < y) {
        while (cell_alive.size() < y) {
            cell_alive.push_front(std::deque<bool>(cell_alive.front().size(), false));
            cell_alive.push_back(std::deque<bool>(cell_alive.back().size(), false));
        }
    }
}

void initWorld(int x, int y) {
    cell_alive = std::deque<std::deque<bool>>(y, std::deque<bool>(x, false));
    /**/
    for (int i = y/3; i < y * 2 / 3; i++) {
        for (int j = x/3; j < x * 2 / 3; j++) {
            cell_alive[i][j] = true;
        }
    }
}

bool isAlive(int x, int y) {
    return cell_alive[y][x];
}

int xCellSize() {
    return cell_alive.front().size();
}

int yCellSize() {
    return cell_alive.size();
}
