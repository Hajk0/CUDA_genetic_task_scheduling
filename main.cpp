#include <iostream>
#include <string>
#include "greedy/include/Greedy.hpp"
#include "genetic/include/Individual.hpp"
#include "genetic/include/Population.hpp"


int main() {
    std::string filename = ".\\data\\jobs_data_100_5_20.txt";
    // Greedy greedy = Greedy(filename);
    // greedy.shuffleTasks();
    // Individual* solution = greedy.generateSolution();
    // solution->printIndividual();
    Population* population = new Population(10, filename);
    population->printPopulation();
    population->selectIndividuals(0.5);

    return 0;
}