//
// Created by mithrandir on 26/11/2021.
//

#include "Stats.hpp"
#include "matplotlibcpp.h"
#include "../src/Neurone.hpp"
#include "Helper.hpp"

namespace plt = matplotlibcpp;

void Stats::getPlotErrorByItr(std::vector<std::pair<std::pair<double, double>, int>>& data_train) {
    std::cout << "[INFO] Generation du plot 'ErrorByIteration'" << std::endl;
    std::vector<int> err = std::vector<int>();
    std::vector<int> iteration = std::vector<int>();

    /**
     * On entraine notre algorithme
     */
    int nombre_erreurs = 0;

    Neurone neurone = Neurone(2);

    std::vector<int> err_train = neurone.train(data_train, 100);

    for(int i =0;i<err_train.size();i++) {
        iteration.push_back(i);
    }

    std::map<std::string, std::string> keywords = {{"label", "Nombre d'erreurs"}};
    plt::plot(iteration, err_train, keywords);
    plt::title("Nombre d'erreur selon l'itération ("+std::to_string(data_train.size())+" exemples)");
    plt::xlabel("Nombre d'itérations");
    plt::ylabel("Nombre d'erreurs");
    plt::legend();
    plt::save("../data/errorbyitr.png");
    plt::close();
    std::cout << "[INFO] FIN Generation du plot 'ErrorByIteration'" << std::endl;
}

void Stats::getPlotErrorByExemple(int max_exemple) {



    for(int i=0;i<=max_exemple;i++){
        std::cout << "[INFO] Generation du plot 'ErrorByExemple'" << std::endl;
        int nb_ex = std::pow(10,i);
        std::vector<int> err = std::vector<int>();
        std::vector<int> iteration = std::vector<int>();

        std::vector<std::pair<std::pair<double, double>, int>> data_train = Helper::gen_data(nb_ex);
        /**
         * On entraine notre algorithme
         */

        Neurone neurone = Neurone(2);

        std::vector<int> err_train = neurone.train(data_train, 100);

        for(int j =0;j<err_train.size();j++) {
            iteration.push_back(j);
        }

        plt::figure();
        plt::clf();
        std::map<std::string, std::string> keywords = {{"label", "Nombre d'erreurs"}};
        plt::plot(iteration, err_train, keywords);
        plt::title("Nombre d'erreurs selon le nombre d'exemples "+std::to_string(nb_ex));
        plt::xlabel("Nombre d'itérations");
        plt::ylabel("Nombre d'erreurs");
        plt::legend();
        plt::save("../data/errorbyexemple_"+std::to_string(nb_ex)+".png");
        plt::close();
        std::cout << "[INFO] FIN Generation du plot 'ErrorByExemple'" << std::endl;


    }

}

void Stats::getPlorErrorByLearningStep(int max_exemple) {

    for(int w=0;w<=max_exemple;w++) {
        int nb_ex = std::pow(10, w);
        std::cout << "[INFO] Generation du plot 'errorbylearning_step_'" << std::to_string(nb_ex) << std::endl;
        plt::figure();
        std::vector<std::pair<std::pair<double, double>, int>> data_train = Helper::gen_data(nb_ex);
        Helper::save_to_file(data_train, "../data/errorByLearningStep_nb_ex_"+std::to_string(nb_ex));
        Neurone::PAS_APPRENTISSAGE = 1;
        for (int i = 0; i <=4; i++) {
            Neurone::PAS_APPRENTISSAGE *= 0.1;
            std::vector<double> err = std::vector<double>();
            std::vector<double> iteration = std::vector<double>();
            /**
             * On entraine notre algorithme
             */

            Neurone neurone = Neurone(2);

            std::vector<int> err_train = neurone.train(data_train, 100);

            for (int j = 0; j < err_train.size(); j++) {
                err.push_back(std::log(err_train[j]));
                iteration.push_back(j);
            }


            std::map<std::string, std::string> keywords = {{"label", "Nombre d'erreurs"}};
            std::string str = std::to_string(Neurone::PAS_APPRENTISSAGE);
            plt::named_plot(str, iteration, err);


        }
        plt::title("Nombre d'erreurs selon le nombre d'exemples \n(variant le pas d'apprentissage)\n("+std::to_string(nb_ex)+" exemples)");
        plt::xlabel("Nombre d'itérations");
        plt::ylabel("Nombre d'erreurs");
        plt::legend();
        plt::save("../data/errorbylearning_step_"+std::to_string(nb_ex)+".png");
        plt::close();
        std::cout << "[INFO] FIN Generation du plot 'errorbylearning_step_'" << std::to_string(nb_ex) << std::endl;
    }
}
