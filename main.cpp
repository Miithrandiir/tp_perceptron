#include <iostream>
#include "./lib/Helper.hpp"
#include "./src/Neurone.hpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {

    /**
     * Affichage des erreurs selon le nombre d'itérations
     */

    std::vector<int> err = std::vector<int>();
    std::vector<int> iteration = std::vector<int>();

    for(int i=0;i<100;i++) {
        std::vector<std::pair<std::pair<double, double>, int>> data_train = Helper::gen_data(700);
        Helper::save_to_file(data_train, "../data/train.txt");

        std::vector<std::pair<std::pair<double, double>, int>> data_test = Helper::gen_data(7000);
        Helper::save_to_file(data_test, "../data/test.txt");

        /**
         * On entraine notre algorithme
         */
        int nombre_erreurs = 0;

        Neurone neurone = Neurone(2);

        neurone.train(data_train, i);

        for (int j = 0; j < data_train.size(); j++) {

            int index = j % data_train.size();
            if (neurone.calc_sortie(data_train[index]) != data_train[index].second) {
                nombre_erreurs++;
            }

        }

        err.push_back(nombre_erreurs);
        iteration.push_back(i);
    }
    plt::plot<int,int>(iteration, err);
    plt::show();



    return 0;
}
