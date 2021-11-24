#include <iostream>
#include "./lib/Helper.hpp"


int main() {

    std::map<std::pair<double, double>, int> data = Helper::gen_data(10);
    Helper::show_data(std::cout, data);
    Helper::save_to_file(data,"../data/train.txt");


    return 0;
}
