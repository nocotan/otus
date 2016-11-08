/**
 * @file routing.hpp
 * @brief this file implements the application routing.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef ROUTING_HPP
#define ROUTING_HPP

#include <functional>
#include <string>


namespace ots {

    struct request {
        const std::string method;
    };

    struct otusRouting {
        const std::string route;
        const std::string method;
        const std::function<std::string(request)> action;
    };

}

#endif
