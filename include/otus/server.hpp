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

namespace ots {

    /**
     * @struct handler
     * @brief request handler
     */
    struct handler {
        typedef boost::network::http::server<handler> server;
        typedef server::string_type server_string;

        //! All routings of application
        std::vector<otusRouting> routings;

        /**
         * @fn
         * operator () for handler
         * @param (_request) boost::network::http::server<handler> request
         * @param (&response) boost::network::http::server<handler>::response &response
         */
        void operator()(server::request const &_request, server::response &response) {
            namespace http = boost::network::http;

            server_string _ip = http::source(_request);
            server_string _path = destination(_request);
            server_string _method = _request.method;
            server_string _source = _request.source;
            server_string _destination = _request.destination;
            server_string _body = _request.body;
            auto _headers = _request.headers;

            // create request
            std::ostringstream method;
            std::ostringstream path;
            std::ostringstream source;
            std::ostringstream destination;
            std::ostringstream body;
            std::vector<header> headers;

            method << _method;
            path << _path;
            source << _source;
            destination << _destination;
            body << _body;

            for (auto _header : _headers) {
                header tmp_header{_header.name, _header.value};
                headers.push_back(tmp_header);
            }

            request req{
                method.str(),
                path.str(),
                source.str(),
                destination.str(),
                body.str(),
                headers
            };

            std::ostringstream data;

            if (routings.size()!=0) {
                int current_number = routing_number(_path, _method);
                if (current_number!=-1) {
                    data << routings[current_number].action(req) << "<br/>";
                }
                else {
                    data << "Routing Error " << _method << " " << _path;
                }
            }
            else {
                render_initial_page(data);
            }

            std::cout << _method << " " << _path << std::endl;

            response = server::response::stock_reply(
                    server::response::ok, data.str()
            );
        }

        void log(...) { }

        private:

            /**
             * @fn
             * @return number of object routing
             * @param (_path) routing path
             * @param (method) HTTP method
             */
            const int routing_number(server_string _path, server_string method) {
                int counter = 0;
                for (otusRouting routing : routings) {
                    if (routing.route == _path && routing.method == method) {
                        return counter;
                    }
                    counter++;
                }
                return -1;
            }

            /**
             * @fn
             * show initial page
             * @param (data) ostringstream
             */
            void render_initial_page(std::ostringstream &data) {
                const std::string indexpage =
                    "<html><head>"
                    "<title>Index</title>"
                    "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css'>"
                    "</head><body>"
                    "<div class='container'>"
                    "<div class='jumbotron' style='background-color: #AFEEEE'>"
                    "<h1>Welcome to otus!</h1>"
                    "Well, let as get the ball rolling!"
                    "</div>"
                    "<div class='jumbotron'>"
                    "<h2>Getting started</h2>"
                    "Here is how to use it!"
                    "<ul>"
                    "<li><h3>1. Set up route</h3></li>"
                    "<li><h3>2. Select template folder and create file</h3></li>"
                    "</ul></div>"
                    "</div></body></html>";

                data << indexpage;
            }
    };

}

#endif
