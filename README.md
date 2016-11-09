# otus
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE) [![GitHub issues](https://img.shields.io/github/issues/nocotan/otus.svg)](https://github.com/nocotan/otus/issues) [![GitHub forks](https://img.shields.io/github/forks/nocotan/otus.svg)](https://github.com/nocotan/otus/network) [![GitHub stars](https://img.shields.io/github/stars/nocotan/otus.svg)](https://github.com/nocotan/otus/stargazers) [![Twitter](https://img.shields.io/twitter/url/https/github.com/nocotan/otus.svg?style=social)](https://twitter.com/intent/tweet?text=Wow:&url=%5Bobject%20Object%5D)  

##### A microframewor for C++

![WelcomePage](https://github.com/nocotan/otus/blob/master/images/Screenshot%202016-11-09%20at%2010.35.22.png)

## Dependencies
- Boost
- cpp-netlib

## Compile

```
g++ -std=c++11 test.cpp -I<path to cpp-netlib> -L<path to cpp-netlib/libs/network/src> -lpthread -lboost_system -lboost_thread -lcppnetlib-uri -lcppnetlib-client-connections -lssl -lcrypto
```

## Usage

### smallest otus app

```c++
#include "otus.h"

int main() {
    ots::otus app = ots::otus();
    app.route("/", "GET", [](ots::request req){
        return "Hello, World!";
    });

    app.run("localhost", "8080");

    return 0;
}
```

### Render template

- ex. template file path: templates/test.html
- otus search template file for "templates" directory at default.

```c++
#include "otus.h"

int main() {
    ots::otus app = ots::otus();
    app.route("/", "GET", [](ots::request req){
        return ots::render_template("test.html");
    });

    app.run("localhost", "8080");

    return 0;
}
```

### User request info

```c++
#include "otus.h"
using namespace std;

int main() {
    // initialize
    ots::otus app = ots::otus();
    
    // routing
    app.route("/", "GET", [](ots::request req)->string{
        cout << req.method << endl;
        cout << req.path << endl;
        cout << req.source << endl;
        cout << req.destination << endl;
        cout << req.body << endl;
        for (auto header : req.headers) {
            cout << header.name << ":" << header.value << endl;
        }
        return ots::render_template("test.html");
    });

    app.route("/", "POST", [](ots::request req)->string{
        cout << req.method << endl;
        cout << req.path << endl;
        cout << req.source << endl;
        cout << req.destination << endl;
        cout << req.body << endl;
        return "OK";
    });


    app.run("localhost", "9000");

    return 0;
}
```

### TODO
- add template engine
- add static folder
