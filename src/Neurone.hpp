//
// Created by mithrandir on 24/11/2021.
//

#ifndef TP4_NEURONE_HPP
#define TP4_NEURONE_HPP


#include <vector>
#include <random>
#include <algorithm>
#define PAS_APPRENTISSAGE 0.001

class Neurone {
    double biais;
    double sortie;
    std::vector<double> poids;
public:
    Neurone(int x_size) : biais(0.5f), sortie(0.0f) {

        poids = std::vector<double>();

        std::random_device dev;
        std::mt19937_64 rng(dev());
        std::uniform_real_distribution<double> dist(0.0f, 1.0f);

        for(int i =0; i< x_size;i++) {
            poids.push_back(dist(rng));
        }

    }


    int calc_sortie(std::pair<std::pair<double,double>,int>&);

    void mise_a_jour(std::pair<std::pair<double,double>,int>&);

    void train(std::vector<std::pair<std::pair<double, double>, int>>& train_test, int iteration);
};

#endif //TP4_NEURONE_HPP
