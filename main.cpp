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
        std::cout << "Aucun fichier de fournis" << std::endl;
        std::cout << "Génération en cours.." << std::endl;
        data_train = Helper::gen_data(100000);
        Helper::save_to_file(data_train, "../data/errorByLearningStep_nb_ex_" + std::to_string(data_train.size()));
        std::cout << "Fin de la génération" << std::endl;
    } else if (argc == 2) {
        std::cout << "fichier fourni" << std::endl;
        std::string test = argv[1];
        data_train = Helper::load_data(test);
    }

    /**
     * Affichage des erreurs selon le nombre d'itérations
     */

    //Affichage des erreurs par le nombre d'itérations
    Stats::getPlotErrorByItr(data_train);
    //Affichage des erreurs par le nombre d'itérations en faisant varier le nombre d'exemples
    //Stats::getPlotErrorByExemple(6);
    //Affichage des erreurs par le nombre d'itérations en faisant varier le nombre d'exemples ainsi que le pas d'apprentissage.
    //Stats::getPlorErrorByLearningStep(6);

    //Valeur à modifier pour jouer sur les erreurs
    data_train = Helper::gen_data(300);
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
