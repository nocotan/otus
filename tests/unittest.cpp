#include <string>
#include <iostream>
#include "../include/otus/app.hpp"
using namespace std;

int main() {
    // initialize
    Otus app = Otus();

    // set static folder
    app.set_static_folder("static");
    // set template folder
    app.set_template_folder("templates");

    // routing
    app.route("/", "GET", []{
        return "OK";
    }());

    app.route("/", "POST", []{
        return "OK";
    }());

    // redefine
    //app.route("/", "GET", []{
    //    return "NG";
    //}());

    return 0;
}
