#ifndef ZOMBIES_GAME_MAP_MAPGEN_H
#define ZOMBIES_GAME_MAP_MAPGEN_H

#include "game/map/map.h"

namespace Game {
    namespace Map {
        /**
         * Generate a new map
         * @param map The map to populate
         */
        void generate(Map& map);
    }
}

#endif
