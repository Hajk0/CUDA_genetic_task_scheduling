#include <iostream>
#include "..\include\Population.hpp"
#include "..\include\Individual.hpp"
#include "..\..\greedy\include\Greedy.hpp"

using namespace std;

Population::Population(int populationSize, const string &filename) {
    this->populationSize = populationSize;
    this->individuals = new Individual*[populationSize];
    Greedy* greedy = new Greedy(filename);

    for (int i = 0; i < this->populationSize; i++) {
        greedy->shuffleTasks();
        this->individuals[i] = greedy->generateSolution();
    }
}

void Population::printPopulation() {
    cout << "Population: " << endl;
    for (int i = 0; i < this->populationSize; i++) {
        cout << "Individual " << i << ": " << endl;
        this->individuals[i]->printIndividual();
    }
}

Population::~Population() {
    for (int i = 0; i < this->populationSize; i++) {
        delete this->individuals[i];
    }
    delete[] this->individuals;
}