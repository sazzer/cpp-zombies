#include "game/map/region.h"

namespace Game {
    namespace Map {
        /**
         * Output operator for regions
         * @param stream The stream to output to
         * @param region The region to output
         * @param the stream for chaining
         */
        std::ostream& operator<<(std::ostream& stream, const Region& region) {
            stream << "[" << region.topLeft() << "-" << region.bottomRight() << "]";
            return stream;
        }
    }
}
