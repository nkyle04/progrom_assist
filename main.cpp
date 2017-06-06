#include <iostream>
#include <string>
#include "parse_arguments.h"

int main(int argc, char** argv) {
    arguments::Arguments args;
    if (arguments::parse_arguments(argc, argv, args) != 0) {
        return 1;
    }

    return 0;
}
