#ifndef ZOMBIES_GAME_MAP_MAP_H
#define ZOMBIES_GAME_MAP_MAP_H

#include "game/map/coords.h"
#include <string>
#include <vector>

namespace Game {
    namespace Map {
        /** An element in the map */
        struct MapElement {
            /** The height of the element */
            unsigned char height = 0;
        };

        /**
         * The overall representation of the Map
         */
        class Map {
        public:
            /**
             * Construct the map
             * @param name The name of the map
             * @param width The width of the map
             * @param height The height of the map
             */
            Map(const std::string& name, const unsigned int width, const unsigned int height);
            /**
             * Get the name of the map
             * @return the name of the map
             */
            const std::string& name() const {
                return name_;
            }
            /**
             * Get the width of the map
             * @return the width of the map
             */
            unsigned int width() const {
                return width_;
            }
            /**
             * Get the height of the map
             * @return the height of the map
             */
            unsigned int height() const {
                return height_;
            }
            /**
             * Get the map element at the given offset
             * @param coords The co-ordinates of the map element
             * @return the Map Element
             */
            const MapElement& getAt(const Coords& coords) const;
            /**
             * Get the map element at the given offset
             * @param coords The co-ordinates of the map element
             * @return the Map Element
             */
            MapElement& getAt(const Coords& coords);
        protected:
        private:
            /** The name of the map */
            std::string name_;
            /** The width of the map */
            unsigned int width_;
            /** The height of the map */
            unsigned int height_;
            /** The actual elements in the map */
            std::vector<MapElement> elements_;
        };
    }
}

#endif

