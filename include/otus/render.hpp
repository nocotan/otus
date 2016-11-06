/**
 * @file render.hpp
 * @brief this file implements the renderer template files.
 * @author nocotan
 * @date 2016/11/5
 */
#ifndef RENDER_HPP
#define RENDER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

namespace ots {

    std::string read_template(std::string filepath) {
        std::ifstream ifs(filepath);
        if (ifs.fail()) {
            std::cerr << "Failed to read template" << std::endl;
        }

        std::istreambuf_iterator<char> it(ifs);
        std::istreambuf_iterator<char> last;
        std::string templatefile(it, last);

        return templatefile;
    }

}

#endif
