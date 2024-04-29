#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
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

    delete greedy;
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
}

Individual* Population::randomCrossover() { // Randomly select two individuals and generate a new individual
    int randomNumber1 = rand() % this->populationSize;
    int randomNumber2;
    while (randomNumber1 == (randomNumber2 = rand() % this->populationSize)); // Choose a different number
    Individual* newIndividual = this->individuals[randomNumber1]->crossover(this->individuals[randomNumber2]);
    
    return newIndividual;
}

void Population::populationCrossover() {
    while (this->freeSpace > 0) {
        Individual* newIndividual = this->randomCrossover();
        if (newIndividual->getFitness() > this->individuals[this->populationSize - this->freeSpace]->getFitness()) {
            delete newIndividual;
        } else {
            delete this->individuals[this->populationSize - this->freeSpace];
            this->individuals[this->populationSize - this->freeSpace] = newIndividual;// XDDDD
        }
        this->freeSpace--;
    }
}

void Population::populationMutation(float mutationProbability, float geneMutationProbability) {
    for (int i = 0; i < this->populationSize; i++) {
        if ((rand() % 100) < mutationProbability * 100) {
            this->individuals[i]->mutate(geneMutationProbability);
        }
    }
}

void Population::simulateGenerations(int generations, float selectPercent, float mutationProbability, float geneMutationProbability) {
    for (int i = 0; i < generations; i++) {
        // std::cout << "Gen " << i << "\n";
        // this->debug(); // Debug
        this->selectIndividuals(selectPercent);
        this->populationCrossover();
        this->populationMutation(mutationProbability, geneMutationProbability);
        // std::cout << "Generation " << i << ": " << "\n";
        // this->printPopulation();
    }
}

void Population::simulateEvolution(int generationsWithoutImprovement, float selectPercent, float mutationProbability, float geneMutationProbability) {
    int bestFitness = this->individuals[0]->getFitness();
    int generations = 0;
    while (generations < generationsWithoutImprovement) {
        this->selectIndividuals(selectPercent);
        this->populationCrossover();
        this->populationMutation(mutationProbability, geneMutationProbability);
        if (this->individuals[0]->getFitness() < bestFitness) {
            bestFitness = this->individuals[0]->getFitness();
            std::cout << "Best fitness: " << bestFitness << "\n";
            generations = 0;
        } else {
            generations++;
        }
    }
}

void Population::debug() {
    std::cout << "---------------------------------------- Population ----------------------------------------" << "\n";
    for (int i = 0; i < this->populationSize; i++) {
        std::cout << "Individual " << i << ": " << "\n";
        this->individuals[i]->debug();
    }
}

Population::~Population() {
    for (int i = 0; i < this->populationSize; i++) {
        delete this->individuals[i];
    }
    delete[] this->individuals;
}