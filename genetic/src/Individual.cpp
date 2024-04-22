#include <iostream>
#include <algorithm>
#include "..\include\Individual.hpp"
#include "Individual.hpp"


Individual::Individual(int numTasks, int numProcessors, int **tasks, int *solution) {
    this->numTasks = numTasks;
    this->numProcessors = numProcessors;
    this->tasks = new int*[numTasks];
    for (int i = 0; i < numTasks; i++) {
        this->tasks[i] = new int[2];
        this->tasks[i][0] = tasks[i][0];
        this->tasks[i][1] = tasks[i][1];
    }
    this->solution = new int[numTasks];
    for (int i = 0; i < numTasks; i++) {
        this->solution[i] = solution[i];
    }
    this->fitness = this->evaluate();
}

void Individual::printIndividual() {
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        std::cout << "Task " << i << " -> Processor " << this->solution[i] << "Task ID " << this->tasks[i][0] << " -> Duration " << this->tasks[i][1] << "\n";
        procOccupation[this->solution[i]] += this->tasks[i][1];
    }

    for (int i = 0; i < this->numProcessors; i++) {
        std::cout << "Processor " << i << ": " << procOccupation[i] << "\n";
    }

    delete[] procOccupation;
}

int Individual::evaluate() { // used in the constructor to set the fitness
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        procOccupation[this->solution[i]] += this->tasks[i][1];
    }

    int maxOccupation = *std::max_element(procOccupation, procOccupation + this->numProcessors);
    delete[] procOccupation;

    return maxOccupation;
}

int Individual::getFitness() { // used in the sort function in Population::selectIndividuals
    return this->fitness;
}