#include "game/map/mapgen.h"
#include <vector>
#include <iostream>

namespace Game {
    namespace Map {
        /**
         * Generate a new map
         * @param map The map to populate
         */
        void generate(Map& map) {
            for (unsigned int w = 0; w < map.width(); ++w) {
                for (unsigned int h = 0; h < map.width(); ++h) {
                    map.getAt(w, h).height = 0;
                }
            }
        }
    }
}

