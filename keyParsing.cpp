//
// Created by damn_lestat on 11/10/19.
//

#include "keyParsing.h"

void keyParsing::parse(int& argc, char **& argv) {

    int long_key_index = -1;
    int opt = 0;

    const static struct option long_keys[] = {
            {"help",no_argument, nullptr,'h'},
            {"version",no_argument, nullptr,'v'},
            {"delete",required_argument, nullptr,'d'},
            {nullptr,0, nullptr,0}
    };

    while((opt = getopt_long(argc,argv,"hvd:",long_keys, &long_key_index)) != -1) {
        static bool occurred_h, occurred_v = false;
        sw:

        if (opt) {
            switch(opt) {
                case 'h':
                    if (!occurred_h) {
                        std::cout << "Key: " << (char) opt << std::endl;
                        occurred_h = true;
                    }
                    break;
                case 'v':
                    if (!occurred_v) {
                        std::cout << "Key: " << (char) opt << std::endl;
                        occurred_v = true;
                    }
                    break;
                case 'd':
                    std::cout << "Key: " << (char) opt << " argument: " << (char*) optarg << std::endl;
                    break;
                default:
                    std::cout << "Invalid option" << std::endl;
                    return;
            }
        } else {
            opt = long_keys[long_key_index].val;
            goto sw;
        }
    }

}
