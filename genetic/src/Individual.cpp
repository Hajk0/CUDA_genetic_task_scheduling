#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <chrono>
#include "..\include\Individual.hpp"
#include "Individual.hpp"


Individual::Individual(int numTasks, int numProcessors, int **tasks) {
    this->numTasks = numTasks;
    this->numProcessors = numProcessors;
    this->tasks = new int*[numTasks];
    this->procOccupation = new int[numProcessors];
    for (int i = 0; i < numTasks; i++) {
        this->tasks[i] = new int[3];
        this->tasks[i][0] = tasks[i][0];
        this->tasks[i][1] = tasks[i][1];
        this->tasks[i][2] = tasks[i][2];
    }
    /*this->solution = new int[numTasks];
    for (int i = 0; i < numTasks; i++) {
        this->solution[i] = solution[i];
    }*/
    this->fitness = this->evaluate();
    this->sortTasks();
}

void Individual::printIndividual() {
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        // std::cout << "Task " << i << " -> Processor " << this->solution[i] << "Task ID " << this->tasks[i][0] << " -> Duration " << this->tasks[i][1] << "\n";
        procOccupation[this->tasks[i][2]] += this->tasks[i][1];
    }

    for (int i = 0; i < this->numProcessors; i++) {
        std::cout << "Processor " << i << ": " << procOccupation[i] << "\n";
    }
    std::cout << "Fitness: " << this->fitness << "\n";

    delete[] procOccupation;
}

int Individual::evaluate() { // used in the constructor to set the fitness
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        procOccupation[this->tasks[i][2]] += this->tasks[i][1];
    }

    int maxOccupation = *std::max_element(procOccupation, procOccupation + this->numProcessors);

    this->procOccupation = procOccupation;
    delete[] procOccupation;

    return maxOccupation;
}

int Individual::getFitness() { // used in the sort function in Population::selectIndividuals
    return this->fitness;
}

Individual* Individual::crossover(Individual* other) {
    int **newTasks = new int*[this->numTasks];
    for (int i = 0; i < this->numTasks; i++) {
        newTasks[i] = new int [3];
        int idThis = this->tasks[i][0];
        int idOther = other->tasks[i][0];
        newTasks[i][0] = this->tasks[i][0];
        newTasks[i][1] = this->tasks[i][1];
        newTasks[i][2] = (rand() % 2) ? this->tasks[i][2] : other->tasks[i][2];
    }

    Individual* newIndividual = new Individual(this->numTasks, this->numProcessors, newTasks);

    for (int i = 0; i < this->numTasks; i++) {
        delete [] newTasks[i];
    }
    delete [] newTasks;

    return newIndividual;
}

void Individual::sortTasks() {
    std::sort(this->tasks, this->tasks + this->numTasks, [](int* a, int* b) {
        return a[0] < b[0];
    });
}

void Individual::mutate(float mutationProbability) {
    for (int i = 0; i < this->numTasks; i++) {
        if ((rand() % 100) < mutationProbability * 100) {
            int randProc = rand() % this->numProcessors;
            int randTaskLength = this->tasks[i][1];
            if (this->procOccupation[randProc] + randTaskLength <= this->fitness) {
                this->tasks[i][2] = randProc;
            }
        }
    }

    this->fitness = this->evaluate(); // Update the fitness after mutation
}

void Individual::debug() {
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        procOccupation[this->tasks[i][2]] += this->tasks[i][1];
    }

    std::cout << "\t";
    for (int i = 0; i < this->numProcessors; i++) {
        std::cout << "Proc " << i << ": " << procOccupation[i] << "; ";
    }
    std::cout << "\tFitness: " << this->fitness << "\n";

    delete[] procOccupation;
}

Individual::~Individual() {
    for (int i = 0; i < this->numTasks; i++) {
        delete[] this->tasks[i];
    }
    delete[] this->tasks;
}