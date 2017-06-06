/**
 * used for parse arguments
 **/

#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H

#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

namespace arguments {

struct Arguments {
    int thread_num;
    std::string symbol_file;
    std::string params_file;
    std::string test_images_file;
    std::string test_labels_file;
    
    Arguments() : thread_num(0),
                  symbol_file(""),
                  params_file(""),
                  test_images_file(""),
                  test_labels_file("") {
    }

    void print() {
        std::cout << "Arguments : "
                  << " thread_num[" << thread_num << "]"
                  << " symbol_file[" << symbol_file << "]"
                  << " params_file[" << params_file << "]"
                  << " test_images_file[" << test_images_file << "]"
                  << " test_labels_file[" << test_labels_file << "]"
                  << std::endl;
    }
};

void print_usage();

int parse_arguments(int argc, char* argv[], Arguments &args);

}
#endif
