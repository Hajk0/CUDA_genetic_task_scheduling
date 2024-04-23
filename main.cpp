#include <iostream>
#include <string>
#include "greedy/include/Greedy.hpp"
#include "genetic/include/Individual.hpp"
#include "genetic/include/Population.hpp"


int main() {
    std::string filename = ".\\data\\jobs_data_500_10_60.txt";
    Greedy greedy = Greedy(filename);
    // greedy.shuffleTasks();
    /*Individual* solution = greedy.generateSolution();
    solution->printIndividual();
    solution->mutate(0.1);
    solution->printIndividual();*/
    // solution->printIndividual();
    Population* population = new Population(1000, filename);
    std::cout << "Initial population: " << "\n";
    // population->printPopulation();
    // population->selectIndividuals(0.5);
    // population->populationCrossover();
    // population->populationMutation(0.1);
    // std::cout << "Final population: " << "\n";
    // population->printPopulation();

    /////////////////////////////////// TEST ///////////////////////////////////
    population->debug();
    population->simulateGenerations(1000, 0.2, 0.1, 0.05);
    // std::cout << "Final population: " << "\n";
    population->debug();



    return 0;
}