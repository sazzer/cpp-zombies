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
        template <typename RNG>
        void seedCells(Map& map, const Region& region, RNG& rng) {
            std::cerr << "Seeding region: " << region << std::endl;
            std::array<Coords, 4> coords = {
                region.topLeft(),
                region.topRight(),
                region.bottomLeft(),
                region.bottomRight()
            };
            
            const Region mapRegion = map.asRegion();
            const Coords middle = mapRegion.middle();

            for (const Coords& c : coords) {
                unsigned int x = c.x();
                unsigned int y = c.y();
                unsigned int dx = x < middle.x() ? x : mapRegion.right() - x;
                unsigned int dy = y < middle.y() ? y : mapRegion.bottom() - y;

                if (dx == 0 || dy == 0) {
                    map.getAt(c).height = 0;
                } else {
                    map.getAt(c).height = std::uniform_int_distribution<unsigned int>(0, 200)(rng);
                }
            }
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

            std::normal_distribution<float> heightRandom(1.0, 0.1);
            mm.height *= (heightRandom(rng));
            tm.height *= (heightRandom(rng));
            bm.height *= (heightRandom(rng));
            ml.height *= (heightRandom(rng));
            mr.height *= (heightRandom(rng));
        }

        /**
         * Generate a new map
         * @param map The map to populate
         */
        void MapGenerator::generate(Map& map) {
            std::random_device rd;
            std::mt19937 e(rd());

            Region initial = map.asRegion();
            std::cerr << "Initial region: " << initial << std::endl;

            std::queue<Region> workQueue;
            std::queue<Region> seedingQueue;
            workQueue.push(initial);
            for (int i = 0; i < 2; ++i) {
                while (!workQueue.empty()) {
                    generateRegions(workQueue.front(), seedingQueue);
                    workQueue.pop();
                }
                while (!seedingQueue.empty()) {
                    const Region& next = seedingQueue.front();
                    seedCells(map, next, e);
                    seedingQueue.pop();
                    workQueue.push(next);
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

