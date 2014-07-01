#include "game/map/mapgen.h"
#include <vector>
#include <iostream>

namespace Game {
    namespace Map {
        /**
         * Generate a new map
         * @param width The width of the map
         * @param height The height of the map
         */
        void generate(const unsigned int width, const unsigned int height) {
            std::vector<MapElement> mapElements(width * height);
            mapElements.resize(width * height);
            for (unsigned int w = 0; w < width; ++w) {
                for (unsigned int h = 0; h < height; ++h) {
                    mapElements[(w * width) + h].height = 0;
                }
            }
        }
    }
}

