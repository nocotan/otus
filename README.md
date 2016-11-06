# otus
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE) [![GitHub issues](https://img.shields.io/github/issues/nocotan/otus.svg)](https://github.com/nocotan/otus/issues) [![GitHub forks](https://img.shields.io/github/forks/nocotan/otus.svg)](https://github.com/nocotan/otus/network) [![GitHub stars](https://img.shields.io/github/stars/nocotan/otus.svg)](https://github.com/nocotan/otus/stargazers) [![Twitter](https://img.shields.io/twitter/url/https/github.com/nocotan/otus.svg?style=social)](https://twitter.com/intent/tweet?text=Wow:&url=%5Bobject%20Object%5D)  
A microframewor for C++

## Dependencies
- Boost
- cpp-netlib

## Compile

```
g++ -std=c++11 test.cpp -I<path to cpp-netlib> -L<path to cpp-netlib/libs/network/src> -lpthread -lboost_system -lboost_thread -lcppnetlib-uri -lcppnetlib-client-connections -lssl -lcrypto
```

## Usage

### smallest otus app

```
#include "otus.h"

int main() {
    ots::otus app = ots::otus();
    app.route("/", "GET", []{
        return "Hello, World!";
    }());
    
    app.run("localhost", "8080");

    return 0;
}
```

### Render template

- ex. template file path: templates/test.html
- otus search template file at "templates" directory at default.

```
#include "otus.h"

int main() {
    ots::otus app = ots::otus();
    app.route("/", "GET", []{
        return ots::render_template("test.html");
    }());
    
    app.run("localhost", "8080");

    return 0;
}
```
