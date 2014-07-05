#ifndef ZOMBIES_GAME_MAP_COORDS_H
#define ZOMBIES_GAME_MAP_COORDS_H

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
            private:
                /** The X-Ordinate */
                unsigned int x_;
                /** The Y-Ordinate */
                unsigned int y_;
        };
    }
}
#endif
