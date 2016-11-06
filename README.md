# otus
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
    Otus app = Otus();
    app.route("/", "GET", []{
        return "Hello, World!";
    }());

    return 0;
}
```

### Render template

- ex. template file path: templates/test.html
- otus is search template file at "templates" directory at default.

```
#include "otus.h"

int main() {
    Otus app = Otus();
    app.route("/", "GET", []{
        return render_template("test.html");
    }());

    return 0;
}
```
