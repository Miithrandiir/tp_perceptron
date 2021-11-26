//
// Created by mithrandir on 24/11/2021.
//

#ifndef TP4_HELPER_HPP
#define TP4_HELPER_HPP

#include <vector>
#include <ostream>

class Helper {
public:
    static std::vector<std::pair<std::pair<double, double>, int>> gen_data(int);
    static std::vector<std::pair<std::pair<double, double>, int>> load_data(std::string&);
    static void show_data(std::ostream& os,std::vector<std::pair<std::pair<double, double>, int>>&);
    static void save_to_file(std::vector<std::pair<std::pair<double, double>, int>>&,std::string);
};


#endif //TP4_HELPER_HPP
