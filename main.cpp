#include <iostream>
#include <string>
#include <ctime>
#include "greedy/include/Greedy.hpp"
#include "genetic/include/Individual.hpp"
#include "genetic/include/Population.hpp"


int main() {
    srand(time(NULL));
    std::string filename = ".\\data\\jobs_data_100_5_10_100.txt";
    Greedy greedy = Greedy(filename);
    Population* population = new Population(100, filename);
    std::cout << "Initial population: " << "\n";

    /////////////////////////////////// TEST ///////////////////////////////////
    population->debug();
    // population->simulateGenerations(1000, 0.5, 0.2, 0.2);
    population->simulateEvolution(10000, 0.5, 0.2, 0.2);
    population->debug();



    return 0;
}