# otus
A microframewor for C++

## Dependencies
- Boost
- cpp-netlib

## Compile

```
g++ -std=c++11 test.cpp -I<path to cpp-netlib> -L<path to cpp-netlib/libs/network/srs> -lpthread -lboost_system -lboost_thread -lcppnetlib-uri -lcppnetlib-client-connections -lssl -lcrypto
```
