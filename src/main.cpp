#include "view_manager.hpp"

#include <string>

int main(int argc, char **argv) {
    std::string name(argv[0]);
    setupView(argc, argv, name.find_last_of('/') + 1);
}
