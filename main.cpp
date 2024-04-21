#include <iostream>
#include "greedy/include/Greedy.h"
#include "genetic/include/Individual.hpp"


int main() {
    std::string filename = ".\\data\\jobs_data_100_5_20.txt";
    Greedy greedy = Greedy(filename);
    Individual* solution = greedy.generateSolution();

    return 0;
}