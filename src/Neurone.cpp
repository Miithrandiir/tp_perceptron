//
// Created by mithrandir on 24/11/2021.
//

#include <iostream>
#include "Neurone.hpp"
int Neurone::calc_sortie(std::pair<std::pair<double, double>, int>& exemple) {

    double sigma = (exemple.first.first*poids[0]+exemple.first.second*poids[1]) - biais;

    return (sigma >= 0) ? 1 : -1;
}

void Neurone::mise_a_jour(std::pair<std::pair<double, double>, int> & exemple) {

    double y = calc_sortie(exemple);

    biais = biais + PAS_APPRENTISSAGE * (exemple.second - y) * (-0.5);
    poids[0] = poids[0] + PAS_APPRENTISSAGE * (exemple.second - y) * exemple.first.first;
    poids[1] = poids[1] + PAS_APPRENTISSAGE * (exemple.second - y) * exemple.first.second;
}

std::vector<int> Neurone::train(std::vector<std::pair<std::pair<double, double>, int>>& train_test, int iteration) {

    std::vector<int> nb_error=std::vector<int>();
    for(int it=0;it<iteration;it++) {

        int nb_error_cpt = 0;
        for(std::pair<std::pair<double,double>,int> item :train_test) {

            int res = calc_sortie(item);

            if(res != item.second) {
                mise_a_jour(item);
                nb_error_cpt++;
            }
        }
        if(nb_error_cpt == 0)
            break;
        nb_error.push_back(nb_error_cpt);



    }
    return nb_error;
}


