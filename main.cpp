#include <iostream>
#include "./lib/Helper.hpp"


int main() {

    std::map<std::pair<double, double>, int> data = Helper::gen_data(10);
    Helper::show_data(data);


    return 0;
}
