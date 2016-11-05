/**
 * @file app.hpp
 * @brief this file implements the application objects of center.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef APP_HPP
#define APP_HPP

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "fields.hpp"
#include "routing.hpp"
#include "server.hpp"
#include "utils.hpp"

class Otus
{
    private:

        //! static folder path
        std::string static_folder;

        //! template folder path
        std::string template_folder;

        //! application routings
        std::vector<OtusRouting> routings;

        /**
         * @fn
         * check initial route
         * @param (route) application route
         * @param (method) routing method
         */
        const bool is_initial_route(std::string route, std::string method) const {
            for (OtusRouting routing : this->routings) {
                if (routing.route == route && routing.method == method) {
                    return false;
                }
            }
            return true;
        }

    public:

        /**
         * @fn
         * Constructor
         */
        Otus()
            : static_folder("static"),
              template_folder("templates")
        {
        };

        /**
         * @fn
         * static folder setter
         * @param (static_folder) static folder path
         */
        void set_static_folder(std::string static_folder)
        {
            this->static_folder = static_folder;
        };

        /**
         * @fn
         * template folder setter
         * @param (template_folder) template folder path
         */
        void set_template_folder(std::string template_folder)
        {
            this->template_folder = template_folder;
        }

        /**
         * @fn
         * routing
         * @param (route) application routing
         * @param (method) routing method
         * @param (action) routing action
         */
        template<class T>
        void route(std::string route, std::string method, T action)
        {
            OtusRouting routing = {route, method, action};

            if (is_initial_route(route, method)) {
                routings.push_back(routing);
            }
            else {
                std::cerr << "Error: redefine routing." << std::endl;
            }
        }

        /**
         * @fn
         * @param (address) server address
         * @param (port) port number
         */
        void run(std::string address, std::string port)
        {
            try {
                std::cout << "server is running: http://" << address << ":" << port << std::endl;

                Handler handler;
                Handler::server::options options(handler);
                Handler::server server_(options.address(address).port(port));
                server_.run();
            }
            catch (std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

};

#endif
