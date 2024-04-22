#include <iostream>
#include "..\include\Population.hpp"
#include "..\include\Individual.hpp"
#include "..\..\greedy\include\Greedy.hpp"


Population::Population(int populationSize, const std::string &filename) {
    this->populationSize = populationSize;
    this->individuals = new Individual*[populationSize];
    Greedy* greedy = new Greedy(filename);

    for (int i = 0; i < this->populationSize; i++) {
        greedy->shuffleTasks();
        this->individuals[i] = greedy->generateSolution();
    }
}

void Population::printPopulation() {
    std::cout << "Population: " << "\n";
    for (int i = 0; i < this->populationSize; i++) {
        std::cout << "Individual " << i << ": " << "\n";
        this->individuals[i]->printIndividual();
    }
}

Population::~Population() {
    for (int i = 0; i < this->populationSize; i++) {
        delete this->individuals[i];
    }
    delete[] this->individuals;
}