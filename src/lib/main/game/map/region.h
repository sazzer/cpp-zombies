#ifndef ZOMBIES_GAME_MAP_REGION_H
#define ZOMBIES_GAME_MAP_REGION_H

#include "game/map/coords.h"
#include <cmath>

namespace Game {
    namespace Map {
        class Region {
            public:
                Region(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2) : 
                    top_(std::min(y1, y2)),
                    bottom_(std::max(y1, y2)),
                    left_(std::min(x1, x2)),
                    right_(std::max(x1, x2)) {}
                /**
                 * Get the top of the region
                 * @return the top
                 */
                unsigned int top() const {
                    return top_;
                }
                /**
                 * Get the bottom of the region
                 * @return the bottom
                 */
                unsigned int bottom() const {
                    return bottom_;
                }
                /**
                 * Get the left of the region
                 * @return the left
                 */
                unsigned int left() const {
                    return left_;
                }
                /**
                 * Get the right of the region
                 * @return the right
                 */
                unsigned int right() const {
                    return right_;
                }
                /**
                 * Get the middle along the X axis
                 * @return the middle
                 */
                unsigned int midX() const {
                    return (left_ + right_) / 2;
                }
                /**
                 * Get the middle along the Y axis
                 * @return the middle
                 */
                unsigned int midY() const {
                    return (top_ + bottom_) / 2;
                }
                /**
                 * Get the top-left of the region
                 * @return the top-left
                 */
                Coords topLeft() const {
                    return Coords(left_, top_);
                }
                /**
                 * Get the bottom-left of the region
                 * @return the bottom-left
                 */
                Coords bottomLeft() const {
                    return Coords(left_, bottom_);
                }
                /**
                 * Get the top-right of the region
                 * @return the top-right
                 */
                Coords topRight() const {
                    return Coords(right_, top_);
                }
                /**
                 * Get the bottom-right of the region
                 * @return the bottom-right
                 */
                Coords bottomRight() const {
                    return Coords(right_, bottom_);
                }
                /**
                 * Get the top-right of the region
                 * @return the top-right
                 */
                Coords topMiddle() const {
                    return Coords(midX(), top_);
                }
                /**
                 * Get the bottom-right of the region
                 * @return the bottom-right
                 */
                Coords bottomMiddle() const {
                    return Coords(midX(), bottom_);
                }
                /**
                 * Get the middle-left of the region
                 * @return the middle-left
                 */
                Coords middleLeft() const {
                    return Coords(left_, midY());
                }
                /**
                 * Get the middle-right of the region
                 * @return the middle-right
                 */
                Coords middleRight() const {
                    return Coords(right_, midY());
                }
                /**
                 * Get the middle of the region
                 * @return the middle
                 */
                Coords middle() const {
                    return Coords(midX(), midY());
                }
            private:
                /** The top of the region */
                unsigned int top_;
                /** The bottom of the region */
                unsigned int bottom_;
                /** The left of the region */
                unsigned int left_;
                /** The right of the region */
                unsigned int right_;
        };
    }
}
#endif
