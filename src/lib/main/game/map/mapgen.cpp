#include "game/map/mapgen.h"
#include <vector>
#include <array>
#include <iostream>
#include <random>
#include "game/map/region.h"
#include <queue>

namespace Game {
    namespace Map {
        /** The initial divisor of the map */
        static const unsigned int INITIAL_DIVISOR = 2;

        /**
         * Generate the next set of regions to work with
         * @param region The region to subdivide
         * @param regions The queue of regions, where we will subdivide and return the first region on the queue
         * @return the region to work with
         */
        Region generateRegions(const Region& region, std::queue<Region>& regions) {
            std::cerr << "Regions starting with: " << regions.size() << std::endl;
            if (region.bottom() - region.top() > 1 && region.right() - region.left() > 1) {
                std::cerr << "Subdividing region: " << region << std::endl;
                std::array<Region, 4> generated = {
                    Region(region.topLeft(), region.middle()),
                    Region(region.topMiddle(), region.middleRight()),
                    Region(region.middleLeft(), region.bottomMiddle()),
                    Region(region.middle(), region.bottomRight())
                };
                for (Region& region : generated) {
                    std::cerr << "Generated region: " << region << std::endl;
                    regions.push(region);
                }
            }
            std::cerr << "Regions left: " << regions.size() << std::endl;
            return region;
        }
        /**
         * Seed the cells at the corners of the given region
         * @param map The map to work with
         * @param region The region to work with
         */
        void seedCells(Map& map, const Region& region) {
            std::cerr << "Seeding region: " << region << std::endl;
            map.getAt(region.topLeft()).height = 100;
            map.getAt(region.bottomLeft()).height = 100;
            map.getAt(region.topRight()).height = 100;
            map.getAt(region.bottomRight()).height = 100;
        }

        /**
         * Actually generate the values for the next region
         * @param map The map to work with
         * @param region The region to work with
         * @param rng The rng to use
         */
        template <typename RNG>
        void generateCells(Map& map, const Region& region, RNG& rng) {
            std::cerr << "Populating region: " << region << std::endl;
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

            mm.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(rng));
            tm.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(rng));
            bm.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(rng));
            ml.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(rng));
            mr.height *= (std::uniform_real_distribution<float>(0.9, 1.1)(rng));
        }

        /**
         * Generate a new map
         * @param map The map to populate
         */
        void MapGenerator::generate(Map& map) {
            std::random_device rd;
            std::mt19937 e(rd());

            Region initial(0, 0, map.width() - 1, map.height() - 1);
            std::cerr << "Initial region: " << initial << std::endl;

            std::queue<Region> workQueue;
            std::queue<Region> seedingQueue;
            seedingQueue.push(initial);
            workQueue.push(initial);
            for (int i = 0; i < 2; ++i) {
                while (!workQueue.empty()) {
                    seedCells(map, workQueue.front());
                    seedingQueue.push(workQueue.front());
                    workQueue.pop();
                }
                while (!seedingQueue.empty()) {
                    generateRegions(seedingQueue.front(), workQueue);
                    seedingQueue.pop();
                }
            }


            while (!workQueue.empty()) {
                Region region = workQueue.front();
                workQueue.pop();
                generateCells(map, generateRegions(region, workQueue), e);
            }
        }
    }
}

