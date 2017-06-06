/*!
 * @file parse_arguments.cpp
 * @brief example for parse arguments
 */

#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "parse_arguments.h"

namespace arguments {

void print_usage() {
    std::cout << "\tUsage:" << std::endl
              << "\t\t-t\tnumber of threads." << std::endl
              << "\t\t-s\tsymbol file to be used." << std::endl
              << "\t\t-p\tparam file to be used." << std::endl
              << "\t\t-i\timages file to be predicted." << std::endl
              << "\t\t-l\tlabels file to be check result." << std::endl
              << "\t\t-h\tprint this usage." << std::endl
              << std::endl;
}

int parse_arguments(int argc, char* argv[], Arguments &args) {
    int opt = 0;
    while ((opt = getopt(argc, argv, "t:s:p:i:l:h")) != -1) {
        switch (opt) {
            case 't':
                args.thread_num = atoi(optarg);
                break;
            case 's':
                args.symbol_file = optarg;
                break;
            case 'p':
                args.params_file = optarg;
                break;
            case 'i':
                args.test_images_file = optarg;
                break;
            case 'l':
                args.test_labels_file = optarg;
                break;
            case 'h':
                print_usage();
                return 0;
            default:
                print_usage();
                return -1;
        }
    }

    return 0;
}

}
