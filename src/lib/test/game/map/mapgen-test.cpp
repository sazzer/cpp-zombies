#include "game/map/mapgen.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(MapGen_Generate) {
    Game::Map::Map map("Test", 1000, 1000);
    Game::Map::MapGenerator mapGenerator;
    mapGenerator.generate(map);
}

