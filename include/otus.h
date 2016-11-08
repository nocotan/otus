/**
 * @file otus.h
 * @brief integration all files.
 *
 * otus is the micro web application framework.
 * @par Usage
 * - Initialize
 *     - Otus app = Otus();
 * - set static & template folder (optional)
 *     - app.set_static_folder("static")
 *     - app.set_template_folder("template")
 * - Routing
 *     - app.route("/", "GET", [](string request){
 *           return "OK";
 *       });
 * - Run app
 *     - app.run("localhost", "9000");
 *
 * @note default template directory: templates
 *
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef OTUS_H
#define OTUS_H

#include "otus/app.hpp"
#include "otus/fields.hpp"
#include "otus/render.hpp"
#include "otus/routing.hpp"
#include "otus/server.hpp"
#include "otus/utils.hpp"

#endif
