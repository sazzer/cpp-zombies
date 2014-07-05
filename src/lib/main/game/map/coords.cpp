#include "game/map/coords.h"

namespace Game {
    namespace Map {
        /**
         * Output operator for coordinates
         * @param stream The stream to output to
         * @param coords The coords to output
         * @param the stream for chaining
         */
        std::ostream& operator<<(std::ostream& stream, const Coords& coords) {
            stream << "(" << coords.x() << ", " << coords.y() << ")";
            return stream;
        }
    }
}
