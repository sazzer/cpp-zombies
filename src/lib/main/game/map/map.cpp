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
         * @param coords The co-ordinates of the map element
         * @return the Map Element
         */
        const MapElement& Map::getAt(const Coords& coords) const {
            unsigned long offset = (coords.x() * height_) + coords.y();
            //std::cerr << "c(" << x << ", " << y << ") => " << offset << std::endl;
            return elements_[offset];
        }
        /**
         * Get the map element at the given offset
         * @param coords The co-ordinates of the map element
         * @return the Map Element
         */
        MapElement& Map::getAt(const Coords& coords) {
            unsigned long offset = (coords.x() * height_) + coords.y();
            //std::cerr << "m(" << x << ", " << y << ") => " << offset << std::endl;
            return elements_[offset];
        }
    }
}
