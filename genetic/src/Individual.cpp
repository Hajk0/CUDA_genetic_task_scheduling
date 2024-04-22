#include <iostream>
#include <algorithm>
#include "..\include\Individual.hpp"
#include "Individual.hpp"


Individual::Individual(int numTasks, int numProcessors, int *tasks, int *solution) {
    this->numTasks = numTasks;
    this->numProcessors = numProcessors;
    this->tasks = new int[numTasks];
    for (int i = 0; i < numTasks; i++) {
        this->tasks[i] = tasks[i];
    }
    this->solution = new int[numTasks];
    for (int i = 0; i < numTasks; i++) {
        this->solution[i] = solution[i];
    }
}

void Individual::printIndividual() {
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        // cout << "Task " << i << " -> Processor " << this->solution[i] << " -> Duration " << this->tasks[i] << endl;
        procOccupation[this->solution[i]] += this->tasks[i];
    }

    for (int i = 0; i < this->numProcessors; i++) {
        std::cout << "Processor " << i << ": " << procOccupation[i] << "\n";
    }

    delete[] procOccupation;
}