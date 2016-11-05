#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "../include/otus/app.hpp"
#include "../include/otus/server.hpp"
#include "../include/otus/render.hpp"
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

    //app.run("localhost", "9000");

    Render render = Render();
    cout << render.read_template("test.html") << endl;

    return 0;
}
