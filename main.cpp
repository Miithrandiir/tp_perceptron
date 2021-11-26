#include <iostream>
#include "./lib/Helper.hpp"
#include "./lib/Stats.hpp"
#include "./src/Neurone.hpp"

double Neurone::PAS_APPRENTISSAGE = 0.01;

#define NB_ITERATION 100

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<double, double>, int>> data_train;

    //Juste l'exécutable
    if (argc == 1) {
        data_train = Helper::gen_data(1000);
        Helper::save_to_file(data_train, "../data/errorByLearningStep_nb_ex_" + std::to_string(1000));
    } else if (argc == 2) {
        std::string test = argv[1];
        data_train = Helper::load_data(test);
    }

    /**
     * Affichage des erreurs selon le nombre d'itérations
     */

//    Stats::getPlotErrorByItr(data_train);
//    Stats::getPlotErrorByExemple(6);
//    Stats::getPlorErrorByLearningStep(6);
    data_train = Helper::gen_data(3000000);
    //Helper::save_to_file(data_train, "../data/train_" + std::to_string(data_train.size()));
    Neurone neurone(2);
    neurone.train(data_train, NB_ITERATION);
    std::vector<double> means{};
    for (int i = 0; i < 20; i++) {

        std::vector<std::pair<std::pair<double, double>, int>> data_test = Helper::gen_data(700);
        Helper::save_to_file(data_train, "../data/test_" + std::to_string(data_test.size()));


        int nb_error = 0;
        for (std::pair<std::pair<double, double>, int> item: data_test) {

            if (neurone.calc_sortie(item) != item.second)
                nb_error++;
        }
        std::cout << "Le perceptron à fait " << nb_error << " erreur(s) ("
                  << (((double) nb_error / (double) data_test.size()) * 100) << "%)" << std::endl;

        means.push_back((((double) nb_error / (double) data_test.size()) * 100) );
    }

    std::cout << std::accumulate(means.begin(),  means.end(), 0.0f)/means.size() << std::endl;
    return 0;
}
