#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "..\include\Greedy.h"
#include "..\..\genetic\include\Individual.hpp"
#include "Greedy.h"

using namespace std;

Greedy::Greedy(const std::string& filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    if (std::getline(file, line)) {
        int pos = line.find(" ");
        this->numTasks = stoi(line.substr(0, pos));
        this->numProcessors = stoi(line.substr(pos + 1));
        this->tasks = new int [this->numTasks];
    }
    int i = 0;
    while (std::getline(file, line) && i < this->numTasks) {

        this->tasks[i] = stoi(line);

        cout << this->tasks[i] << endl;
        i++;
    }

    file.close();
}

Individual* Greedy::generateSolution() {
    int* solution = new int[this->numTasks];
    int* procOccupation = new int[this->numProcessors];
    for (int i = 0; i < this->numTasks; i++) {
        solution[i] = 0;
    }
    for (int i = 0; i < this->numProcessors; i++) {
        procOccupation[i] = 0;
    }

    for (int i = 0; i < this->numTasks; i++) {
        int minOccupation = procOccupation[0];
        int minProc = 0;
        for (int j = 0; j < this->numProcessors; j++) {
            if (procOccupation[j] < minOccupation) {
                minOccupation = procOccupation[j];
                minProc = j;
            }
        }

        solution[i] = minProc;
        procOccupation[minProc] += this->tasks[i];
    }

    /*for (int i = 0; i < this->numTasks; i++) {
        cout << solution[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < this->numProcessors; i++) {
        cout << procOccupation[i] << " ";
    }*/

    return (new Individual(this->numTasks, this->numProcessors, this->tasks, solution));
}

void Greedy::shuffleTasks() {
    for (int i = 0; i < this->numTasks; i++) {
        int j = rand() % this->numTasks;
        int tmp = this->tasks[i];
        this->tasks[i] = this->tasks[j];
        this->tasks[j] = tmp;
    }
}

Greedy::~Greedy() {
    std::cout << "Greedy destructor" << std::endl;

    delete[] this->tasks;
}
