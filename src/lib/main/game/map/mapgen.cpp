#include "game/map/mapgen.h"
#include <vector>
#include <iostream>
#include <random>
#include "game/map/region.h"

namespace Game {
    namespace Map {
        /** The initial divisor of the map */
        static const unsigned int INITIAL_DIVISOR = 2;
        /**
         * Generate a new map
         * @param map The map to populate
         */
        void MapGenerator::generate(Map& map) {
            std::random_device rd;
            std::mt19937 e(rd());
            unsigned int widthDivision = map.width() / INITIAL_DIVISOR;
            unsigned int heightDivision = map.height() / INITIAL_DIVISOR;

            // Set the initial values
            for (unsigned int x = 0; x < map.width(); x += widthDivision) {
                for (unsigned int y = 0; y < map.height(); y += heightDivision) {
                    MapElement& elem = map.getAt({x, y});
                    elem.height = std::uniform_int_distribution<unsigned int>(100, 200)(e);
                    std::cerr << "(" << x << ", " << y << ") = " << (unsigned int)(elem.height) << std::endl;
                }
            }

            // Now we start to iterate
            while (widthDivision > 1 && heightDivision > 1) {
                std::cerr << widthDivision << " x " << heightDivision << std::endl;
                for (unsigned int x = 0; x < map.width(); x += widthDivision) {
                    for (unsigned int y = 0; y < map.height(); y += heightDivision) {
                        Region region(x, y, x + widthDivision, y + heightDivision);

                        MapElement& tl = map.getAt(region.topLeft());
                        MapElement& tm = map.getAt(region.topMiddle());
                        MapElement& tr = map.getAt(region.topRight());

                        MapElement& ml = map.getAt(region.middleLeft());
                        MapElement& mm = map.getAt(region.middle());
                        MapElement& mr = map.getAt(region.middleRight());

                        MapElement& bl = map.getAt(region.bottomLeft());
                        MapElement& bm = map.getAt(region.bottomMiddle());
                        MapElement& br = map.getAt(region.bottomRight());

                        mm.height = (tl.height + tr.height + bl.height + br.height) / 4;
                        tm.height = (tl.height + tr.height) / 2;
                        bm.height = (bl.height + br.height) / 2;
                        ml.height = (tl.height + bl.height) / 2;
                        mr.height = (tr.height + br.height) / 2;

                        mm.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(e));
                        tm.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(e));
                        bm.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(e));
                        ml.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(e));
                        mr.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(e));
                    }
                }

                widthDivision /= 2;
                heightDivision /= 2;
            }
        }
    }
}

