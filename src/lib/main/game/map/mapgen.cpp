#include "game/map/mapgen.h"
#include <vector>
#include <iostream>
#include <random>

namespace Game {
    namespace Map {
        /**
         * Generate a new map
         * @param map The map to populate
         */
        void MapGenerator::generate(Map& map) {
            std::random_device rd;
            std::mt19937 e(rd());
            std::uniform_int_distribution<unsigned int> widthDist(0, map.width() - 1);
            std::uniform_int_distribution<unsigned int> heightDist(0, map.height() - 1);
            std::uniform_int_distribution<unsigned char> depthDist(0, 250);
            std::uniform_int_distribution<unsigned int> countDist(map.width(), map.width() * map.height());
            unsigned int count = countDist(e);

            for (unsigned int i = 0; i < count; ++i) {
                unsigned int x = widthDist(e);
                unsigned int y = heightDist(e);
                unsigned char h = depthDist(e);
                MapElement& elem = map.getAt(x, y);
                elem.height = h;
            }
        }
    }
}

