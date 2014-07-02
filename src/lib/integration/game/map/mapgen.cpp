#include <iostream>
#include "game/map/mapgen.h"
#include <png.h>

/**
 * Write the given map to a PNG file
 * @param map The map to write
 */
void mapwriter(const Game::Map::Map& map, const std::string filename) {
    std::cerr << "Writing map to file: " << filename << std::endl;
    auto filedel = [](FILE* fp) { fclose(fp); std::cerr << "Closed file" << std::endl; };
    std::unique_ptr<FILE, decltype(filedel)> fp(fopen(filename.c_str(), "wb"), filedel);
    if (!fp) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    auto pngptrdel = [](png_struct* png_ptr) { png_destroy_write_struct(&png_ptr, nullptr); std::cerr << "Closed PNG" << std::endl; };
    std::unique_ptr<png_struct, decltype(pngptrdel)> png_ptr(png_create_write_struct(PNG_LIBPNG_VER_STRING, 
        nullptr, // user_error_ptr
        nullptr, // user_error_fn
        nullptr),// user_warning_fn
        pngptrdel);
    if (!png_ptr) {
        std::cerr << "Error opening PNG" << std::endl;
        return;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr.get());

    png_init_io(png_ptr.get(), fp.get());
    png_set_IHDR(png_ptr.get(), 
        info_ptr,
        map.width(),
        map.height(),
        8, 
        PNG_COLOR_TYPE_RGB,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png_ptr.get(), info_ptr);

    std::vector<png_bytep> rows(map.height());
    for (unsigned int y = 0; y < map.height(); ++y) {
        rows[y] = new png_byte[map.width() * 3];
        for (unsigned int x = 0; x < map.width(); ++x) {
            const Game::Map::MapElement& element = map.getAt(x, y);

            rows[y][(x * 3) + 0] = element.height; // R
            rows[y][(x * 3) + 1] = element.height; // G
            rows[y][(x * 3) + 2] = element.height; // B
        }
    }
    png_write_image(png_ptr.get(), &(rows[0]));
    png_write_end(png_ptr.get(), nullptr);
}

int main(void) {
    std::cerr << "Map Generation Test" << std::endl;
    Game::Map::Map map("Test", 10000, 10000);
    Game::Map::generate(map);
    mapwriter(map, "/tmp/map.png");
}
