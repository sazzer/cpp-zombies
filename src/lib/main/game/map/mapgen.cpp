#include "game/map/mapgen.h"
#include <vector>
#include <iostream>
#include <random>

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
                        unsigned int farX = x + widthDivision;
                        unsigned int farY = y + heightDivision;
                        unsigned int midX = x + (widthDivision / 2);
                        unsigned int midY = y + (heightDivision / 2);
//                        std::cerr << "(" << x << ", " << y << ") -> (" << farX << ", " << farY << ")" << std::endl;

                        MapElement& tl = map.getAt({x, y});
                        MapElement& tm = map.getAt({midX, y});
                        MapElement& tr = map.getAt({farX, y});

                        MapElement& ml = map.getAt({x, midY});
                        MapElement& mm = map.getAt({midX, midY});
                        MapElement& mr = map.getAt({farX, midY});

                        MapElement& bl = map.getAt({x, farY});
                        MapElement& bm = map.getAt({midX, farY});
                        MapElement& br = map.getAt({farX, farY});

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

