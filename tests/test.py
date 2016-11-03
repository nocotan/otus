# -*- coding: utf-8 -*-

import os
import subprocess


def compile_test(filename):
    cmd = "/usr/bin/g++ -std=c++11 {}".format(filename)
    if (os.system(cmd) != 0):
        print("Compile Error")

    result = subprocess.call(cmd.strip().split(" "))

    return result


if __name__ == '__main__':
    print(compile_test("unittest.cpp"))

