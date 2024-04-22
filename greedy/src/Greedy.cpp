#include <iostream>
#include <fstream>
#include <string>
#include "..\include\Greedy.hpp"
#include "..\..\genetic\include\Individual.hpp"


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
        this->tasks = new int* [this->numTasks];
    }
    int i = 0;
    while (std::getline(file, line) && i < this->numTasks) {

        this->tasks[i] = new int[2];
        this->tasks[i][0] = i;
        this->tasks[i][1] = stoi(line);

        std::cout << this->tasks[i][0] << " " << this->tasks[i][1] << "\n";
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
        int taskID = this->tasks[i][0]; // add by task ID to enable getting solution by task ID
        std::cout << "Task " << taskID << " -> ";
        for (int j = 0; j < this->numProcessors; j++) {
            if (procOccupation[j] < minOccupation) {
                minOccupation = procOccupation[j];
                minProc = j;
            }
        }
        solution[taskID] = minProc;
        procOccupation[minProc] += this->tasks[taskID][1];
    }
    
    return (new Individual(this->numTasks, this->numProcessors, this->tasks, solution));
}

void Greedy::shuffleTasks() {
    for (int i = 0; i < this->numTasks; i++) {
        int j = rand() % this->numTasks;
        int iTaskId = this->tasks[i][0];
        int jTaskId = this->tasks[j][0];
        int tmp = this->tasks[i][1];
        this->tasks[i][1] = this->tasks[j][1];
        this->tasks[j][1] = tmp;
        this->tasks[i][0] = jTaskId;
        this->tasks[j][0] = iTaskId;
    }
}

Greedy::~Greedy() {
    delete[] this->tasks;
}
