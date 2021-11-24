//
// Created by mithrandir on 24/11/2021.
//

#ifndef TP4_HELPER_HPP
#define TP4_HELPER_HPP

#include <map>

class Helper {
public:
    static std::map<std::pair<double, double>, int> gen_data(int);
    static void show_data(std::ostream& os,std::map<std::pair<double, double>, int>&);
    static void save_to_file(std::map<std::pair<double, double>, int>&,std::string);
};


#endif //TP4_HELPER_HPP
