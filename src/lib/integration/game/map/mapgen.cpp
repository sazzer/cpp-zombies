#include <iostream>
#include "game/map/mapgen.h"

int main(void) {
    std::cerr << "Map Generation Test" << std::endl;
    Game::Map::Map map("Test", 10000, 10000);
    Game::Map::generate(map);
}
