/**
 * @file server.hpp
 * @brief this file implements the http server.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>

#include <boost/network/include/http/server.hpp>



struct Handler {
    typedef boost::network::http::server<Handler> server;

    void operator()(server::request const &request, server::response &response) {
        namespace http = boost::network::http;
        typedef server::string_type server_string;

        server_string ip = http::source(request);
        server_string path = destination(request);

        std::ostringstream data;

        data << "HTTP Server is running!" << "<br/>";

        response = server::response::stock_reply(
                server::response::ok, data.str()
        );
    }

    void log(...) { }
};

#endif
