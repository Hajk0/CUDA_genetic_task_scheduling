#include <iostream>
#include <algorithm>
#include "..\include\Population.hpp"
#include "..\include\Individual.hpp"
#include "..\..\greedy\include\Greedy.hpp"


Population::Population(int populationSize, const std::string &filename) {
    this->populationSize = populationSize;
    this->freeSpace = 0;
    this->individuals = new Individual*[populationSize];
    Greedy* greedy = new Greedy(filename);

    for (int i = 0; i < this->populationSize; i++) {
        greedy->shuffleTasks();
        this->individuals[i] = greedy->generateSolution();
        // this->individuals[i]->printIndividual(); // Debug
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
    this->freeSpace = this->populationSize - this->populationSize * selectPercent;
    this->populationSize = this->populationSize * selectPercent; // Select the best individuals (I don't realocate memory)

    std::cout << "Selected individuals: " << "\n";
    for (int i = 0; i < this->populationSize; i++) {
        std::cout << "Individual " << i << ": " << "\n";
        this->individuals[i]->printIndividual();
    }
}

Individual* Population::randomCrossover() { // Randomly select two individuals and generate a new individual
    int randomNumber1 = rand() % this->populationSize;
    int randomNumber2;
    while (randomNumber1 == (randomNumber2 = rand() % this->populationSize)); // Choose a different number
    Individual* newIndividual = this->individuals[randomNumber1]->crossover(this->individuals[randomNumber2]);

    return newIndividual;
}

Population::~Population() {
    for (int i = 0; i < this->populationSize; i++) {
        delete this->individuals[i];
    }
    delete[] this->individuals;
}