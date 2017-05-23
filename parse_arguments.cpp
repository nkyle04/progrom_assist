/*!
 * @file parse_arguments.cpp
 * @brief example for parse arguments
 */

#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>

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
                return -1;
            default:
                print_usage();
                return -1;
        }
    }

    args.print();

    if (args.thread_num <= 0 
        || args.symbol_file == "" 
        || args.params_file == ""
        || args.test_images_file == ""
        || args.test_labels_file == "") {
        std::cout << "input argument not valid!" << std::endl;
        return -1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    Arguments args;
    if (parse_arguments(argc, argv, args) != 0) {
        return 1;
    }

    return 0;
}
