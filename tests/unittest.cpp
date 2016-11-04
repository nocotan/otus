#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "../include/otus/app.hpp"
#include "../include/otus/server/server.hpp"
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

    size_t num_threads = boost::lexical_cast<std::size_t>(2);
    http::server3::server s("127.0.0.1", "9000", ".", num_threads);
        s.run();

    return 0;
}
