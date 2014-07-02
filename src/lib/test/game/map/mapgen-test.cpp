#include "game/map/mapgen.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(MapGen_Generate) {
    Game::Map::Map map("Test", 10000, 10000);
    Game::Map::generate(map);
}
