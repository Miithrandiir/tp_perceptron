#include <iostream>
#include "./lib/Helper.hpp"
#include "./lib/Stats.hpp"
#include "./src/Neurone.hpp"

double Neurone::PAS_APPRENTISSAGE = 0.01;

int main() {

    /**
     * Affichage des erreurs selon le nombre d'itérations
     */
    std::vector<std::pair<std::pair<double, double>, int>> data_train = Helper::gen_data(700);
    Stats::getPlotErrorByItr(data_train);
    Stats::getPlotErrorByExemple(6);
    Stats::getPlorErrorByLearningStep(6);


    return 0;
}
