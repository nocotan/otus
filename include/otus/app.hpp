/**
 * @file app.hpp
 * @brief this file implements the application objects of center.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef APP_HPP
#define APP_HPP

#include <functional>
#include <string>
#include <vector>

#include "routing.hpp"

class Otus
{
    private:

        //! static folder path
        std::string static_folder;

        //! template folder path
        std::string template_folder;

        //! application routings
        std::vector<OtusRouting> routings;

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
            routings.push_back(routing);
        }

};

#endif
