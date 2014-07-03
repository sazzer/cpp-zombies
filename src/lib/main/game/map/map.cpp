#include "game/map/map.h"
#include <iostream>

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
            std::cerr << "Elements: " << (width * height) << std::endl;
        }
        /**
         * Get the map element at the given offset
         * @param x The X Offset
         * @param y The Y Offset
         * @return the Map Element
         */
        const MapElement& Map::getAt(const unsigned int x, const unsigned int y) const {
            unsigned long offset = (x * height_) + y;
            //std::cerr << "c(" << x << ", " << y << ") => " << offset << std::endl;
            return elements_[offset];
        }
        /**
         * Get the map element at the given offset
         * @param x The X Offset
         * @param y The Y Offset
         * @return the Map Element
         */
        MapElement& Map::getAt(const unsigned int x, const unsigned int y) {
            unsigned long offset = (x * height_) + y;
            //std::cerr << "m(" << x << ", " << y << ") => " << offset << std::endl;
            return elements_[offset];
        }
    }
}
