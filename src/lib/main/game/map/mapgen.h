#ifndef ZOMBIES_GAME_MAP_MAPGEN_H
#define ZOMBIES_GAME_MAP_MAPGEN_H

#include <string>

namespace Game {
    namespace Map {
        /** An element in the map */
        struct MapElement {
            /** The height of the element */
            unsigned char height;
        };
        /**
         * Generate a new map
         * @param name The name of the map
         * @param width The width of the map
         * @param height The height of the map
         */
        void generate(const std::string name, 
            const unsigned int width, 
            const unsigned int height);
    }
}

#endif
