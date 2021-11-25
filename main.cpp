#include <iostream>
#include "./lib/Helper.hpp"
#include "./src/Neurone.hpp"


int main() {
    std::vector<std::pair<std::pair<double, double>, int>> data_train = Helper::gen_data(700);
    Helper::save_to_file(data_train, "../data/train.txt");

    std::vector<std::pair<std::pair<double, double>, int>> data_test = Helper::gen_data(7000);
    Helper::save_to_file(data_test, "../data/test.txt");

    /**
     * On entraine notre algorithme
     */
    int nombre_erreurs = 0;

    Neurone neurone = Neurone(2);

    neurone.train(data_train, 100);

    for (int j = 0; j < data_train.size(); j++) {

        int index = j % data_train.size();
        if (neurone.calc_sortie(data_train[index]) != data_train[index].second) {
            nombre_erreurs++;
        }

    }

    std::cout << "Nombre d'erreurs en train " << nombre_erreurs << " "
              << (((double) nombre_erreurs / (double) data_train.size()) * 100) << "%" << std::endl;

    nombre_erreurs = 0;

    for (int j = 0; j < data_test.size(); j++) {

        int index = j % data_test.size();
        if (neurone.calc_sortie(data_test[index]) != data_test[index].second) {
            nombre_erreurs++;
        }

    }

    std::cout << "Nombre d'erreurs en test " << nombre_erreurs << " "
              << (((double) nombre_erreurs / (double) data_test.size()) * 100) << "%" << std::endl;

    std::cout << std::endl;
    return 0;
}
