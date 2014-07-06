#ifndef ZOMBIES_GAME_MAP_COORDS_H
#define ZOMBIES_GAME_MAP_COORDS_H

#include <ostream>

namespace Game {
    namespace Map {
        /**
         * Representation of some co-ordinates on the map
         */
        class Coords {
            public:
                /**
                 * Construct the co-ordinates
                 * @param x The X-ordinate
                 * @param y The Y-ordinate
                 */
                Coords(const unsigned int x, const unsigned int y) : x_(x), y_(y) {}
                /**
                 * Get the X-Ordinate
                 * @return the X-Ordinate
                 */
                const unsigned int& x() const {
                    return x_;
                }
                /**
                 * Get the Y-Ordinate
                 * @return the Y-Ordinate
                 */
                const unsigned int& y() const {
                    return y_;
                }
                /**
                 * Return a new coords object offset along the X Axis by a given amount
                 * @param dx The amount to shift by
                 * @return the new coords object
                 */
                Coords plusX(unsigned int dx) const {
                    return plus(dx, 0);
                }
                /**
                 * Return a new coords object offset along the Y Axis by a given amount
                 * @param dy The amount to shift by
                 * @return the new coords object
                 */
                Coords plusY(unsigned int dy) const {
                    return plus(0, dy);
                }
                /**
                 * Return a new coords object offset by the given amounts
                 * @param dx The amount to shift by
                 * @param dy The amount to shift by
                 * @return the new coords object
                 */
                Coords plus(unsigned int dx, unsigned int dy) const {
                    return Coords(x_ + dx, y_ + dy);
                }
                /**
                 * Comparison operator for Coords
                 * @param other The second object to compare
                 * @return True if the objects are the same
                 */
                bool operator==(const Coords& other) {
                    return (x_ == other.x_) && (y_ == other.y_);
                }
                /**
                 * Comparison operator for Coords
                 * @param other The second object to compare
                 * @return True if the objects are the same
                 */
                bool operator!=(const Coords& other) {
                    return !(*this == other);
                }
            private:
                /** The X-Ordinate */
                unsigned int x_;
                /** The Y-Ordinate */
                unsigned int y_;
        };
        /**
         * Output operator for coordinates
         * @param stream The stream to output to
         * @param coords The coords to output
         * @param the stream for chaining
         */
        std::ostream& operator<<(std::ostream& stream, const Coords& coords);
    }
}
#endif
