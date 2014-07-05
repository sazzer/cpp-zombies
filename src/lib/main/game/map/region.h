#ifndef ZOMBIES_GAME_MAP_REGION_H
#define ZOMBIES_GAME_MAP_REGION_H

#include "game/map/coords.h"
#include <cmath>

namespace Game {
    namespace Map {
        /**
         * A region of a map
         */
        class Region {
            public:
                /**
                 * Construct the region from the raw coordinates
                 * @param x1 One of the X coordinates
                 * @param y1 One of the Y coordinates
                 * @param x2 The other one of the X coordinates
                 * @param y2 The other one of the Y coordinates
                 */
                Region(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2) : 
                    top_(std::min(y1, y2)),
                    bottom_(std::max(y1, y2)),
                    left_(std::min(x1, x2)),
                    right_(std::max(x1, x2)) {}
                /**
                 * Construct the region from coordinates
                 * @param tl The top left coordinate
                 * @param bl The bottom right coordinate
                 */
                Region(const Coords& tl, const Coords& br) : 
                    top_(std::min(tl.y(), br.y())),
                    bottom_(std::max(tl.y(), br.y())),
                    left_(std::min(tl.x(), br.x())),
                    right_(std::max(tl.x(), br.x())) {}
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
                /**
                 * Comparison operator for Region
                 * @param other The second object to compare
                 * @return True if the objects are the same
                 */
                bool operator==(const Region& other) {
                    return (top_ == other.top_) &&
                        (bottom_ == other.bottom_) &&
                        (left_ == other.left_) &&
                        (right_ == other.right_);
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
