#include "game/map/mapgen.h"
#include <vector>
#include <iostream>

namespace Game {
    namespace Map {
        /**
         * Generate a new map
         * @param name The name of the map
         * @param width The width of the map
         * @param height The height of the map
         */
        void generate(const std::string name, 
            const unsigned int width, 
            const unsigned int height) {
            std::vector<MapElement> mapElements(width * height);
        }
    }
}

