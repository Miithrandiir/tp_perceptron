//
// Created by mithrandir on 24/11/2021.
//

#include "Helper.hpp"
#include <random>
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

std::vector<std::pair<std::pair<double, double>, int>> Helper::gen_data(int number_of_gen) {

    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    std::vector<std::pair<std::pair<double, double>, int>> res = std::vector<std::pair<std::pair<double, double>, int>>();

    for (int i = 0; i < number_of_gen; i++) {

        double x1 = dist(rng);
        double x2 = dist(rng);
        //res.emplace_back(std::make_pair(std::make_pair(x1,x2), ((x1+x2-1 > 0) ? 1 : -1)));
        res.emplace_back(std::make_pair(std::make_pair(x1,x2), ((x1+x2-1 > 0 && x2 > 0.5) ? 1 : -1)));

    }

    return res;
}

void Helper::show_data(std::ostream& os, std::vector<std::pair<std::pair<double, double>, int>>& data) {
    for(std::pair<std::pair<double,double>, int> item : data) {

        os << item.first.first << " " << item.first.second << " " << item.second << std::endl;

    }

}

void Helper::save_to_file(std::vector<std::pair<std::pair<double, double>, int>> & data, std::string filename) {

    std::ofstream ofs(filename);


    std::stringstream ss = std::stringstream();

    show_data(ss, data);

    ofs << ss.str();

    ofs.close();
}

std::vector<std::pair<std::pair<double, double>, int>> Helper::load_data(std::string& filename) {

    std::ifstream iss;
    iss.open(filename);

    std::string line;
    std::vector<std::pair<std::pair<double,double>,int>> res{};

    while(std::getline(iss, line)) {

        std::pair<std::pair<double,double>,int> tmp{};
        std::string subline;
        std::getline(iss, subline, ' ');
        tmp.first.first = std::stod(subline);
        std::getline(iss, subline, ' ');
        tmp.first.second = std::stod(subline);
        std::getline(iss, subline, ' ');
        tmp.second = std::stoi(subline);

        res.push_back(tmp);

    }

    return res;

}
