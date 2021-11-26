#include <iostream>
#include "./lib/Helper.hpp"
#include "./lib/Stats.hpp"
#include "./src/Neurone.hpp"

//double Neurone::PAS_APPRENTISSAGE = 0.0001;
double Neurone::PAS_APPRENTISSAGE = 0.01;

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<double, double>, int>> data_train;

    //Juste l'exécutable
    if(argc == 1) {
        data_train = Helper::gen_data(50);
        Helper::save_to_file(data_train, "../data/errorByLearningStep_nb_ex_"+std::to_string(50));
    } else if(argc == 2) {
        std::string test = argv[1];
        data_train = Helper::load_data(test);
    }

    /**
     * Affichage des erreurs selon le nombre d'itérations
     */

    Stats::getPlotErrorByItr(data_train);
    Stats::getPlotErrorByExemple(6);
    Stats::getPlorErrorByLearningStep(6);


    return 0;
}
