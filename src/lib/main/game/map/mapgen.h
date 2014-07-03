#ifndef ZOMBIES_GAME_MAP_MAPGEN_H
#define ZOMBIES_GAME_MAP_MAPGEN_H

#include "game/map/map.h"

namespace Game {
    namespace Map {
        /**
         * Mechanism to generate a map
         */
        class MapGenerator {
        public:
            /**
             * Generate a new map
             * @param map The map to populate
             */
            void generate(Map& map);
        };
    }
}

#endif
