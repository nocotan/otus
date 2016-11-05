/**
 * @file server.hpp
 * @brief this file implements the http server.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>

#include <boost/network/include/http/server.hpp>

#include "routing.hpp"


struct Handler {
    typedef boost::network::http::server<Handler> server;
    typedef server::string_type server_string;

    std::vector<OtusRouting> routings;

    void operator()(server::request const &request, server::response &response) {
        namespace http = boost::network::http;

        server_string ip = http::source(request);
        server_string path = destination(request);

        server_string method = request.method;

        std::ostringstream data;

        int current_number = routing_number(path, method);
        if (current_number!=-1) {
            data << routings[current_number].action << "<br/>";
        }
        else {
            data << "Routing Error " << method << " " << path;
        }

        std::cout << method << " " << path << std::endl;

        response = server::response::stock_reply(
                server::response::ok, data.str()
        );
    }

    void log(...) { }

    private:
        const int routing_number(server_string path, server_string method) {
            int counter = 0;
            for (OtusRouting routing : routings) {
                if (routing.route == path && routing.method == method) {
                    return counter;
                }
                counter++;
            }
            return -1;
        }
};

#endif
