#include <iostream>
#include <algorithm>
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

void Population::selectIndividuals(float selectPercent) { // Selection by sorting the individuals by fitness
    // Steady state selection
    std::sort(this->individuals, this->individuals + this->populationSize, [](Individual* a, Individual* b) {
        return a->getFitness() < b->getFitness();
    });
    this->populationSize = this->populationSize * selectPercent; // Select the best individuals (I don't realocate memory)

    std::cout << "Selected individuals: " << "\n";
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