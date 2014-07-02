#include "game/map/map.h"

namespace Game {
    namespace Map {
        /**
         * Construct the map
         * @param name The name of the map
         * @param width The width of the map
         * @param height The height of the map
         */
        Map::Map(const std::string& name, const unsigned int width, const unsigned int height) : name_(name), width_(width), height_(height) {
            elements_.resize(width * height);
        }
        /**
         * Get the map element at the given offset
         * @param x The X Offset
         * @param y The Y Offset
         * @return the Map Element
         */
        const MapElement& Map::getAt(const unsigned int x, const unsigned int y) const {
            return elements_[(x * width_) + y];
        }
        /**
         * Get the map element at the given offset
         * @param x The X Offset
         * @param y The Y Offset
         * @return the Map Element
         */
        MapElement& Map::getAt(const unsigned int x, const unsigned int y) {
            return elements_[(x * width_) + y];
        }
    }
}
