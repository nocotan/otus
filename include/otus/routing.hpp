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

    /**
     * @struct header
     * @brief header
     */
    struct header {
        const std::string name;
        const std::string value;
    };

    /**
     * @struct request
     * @brief request
     */
    struct request {
        const std::string method;
        const std::string path;
        const std::string source;
        const std::string destination;
        const std::string body;
        const std::vector<header> headers;
    };

    /**
     * @struct otusRouting
     * @brief routing
     */
    struct otusRouting {
        const std::string route;
        const std::string method;
        const std::function<std::string(request)> action;
    };

}

#endif
