#include <iostream>
#include "..\include\Individual.hpp"


using namespace std;

Individual::Individual(int numTasks, int numProcessors, int *tasks, int *solution) {
    this->numTasks = numTasks;
    this->numProcessors = numProcessors;
    this->tasks = tasks;
    this->solution = solution;
}