#include <iostream>
#include "greedy/include/Greedy.h"


int main() {
    std::string filename = ".\\data\\jobs_data_100_5_20.txt";
    Greedy greedy = Greedy(filename);
    int* solution = greedy.generateSolution();

    return 0;
}