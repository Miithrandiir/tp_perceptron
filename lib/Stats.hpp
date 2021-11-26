//
// Created by mithrandir on 26/11/2021.
//

#ifndef TP4_STATS_HPP
#define TP4_STATS_HPP


#include <utility>
#include <vector>

class Stats {
public:
    static void getPlotErrorByItr(std::vector<std::pair<std::pair<double, double>, int>>&);
    static void getPlotErrorByExemple(int);
    static void getPlorErrorByLearningStep(int);
};


#endif //TP4_STATS_HPP
