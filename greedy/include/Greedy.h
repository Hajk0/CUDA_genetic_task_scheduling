#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include <fstream>
#include <string>
#include "..\..\genetic\include\Individual.hpp"

class Greedy {
private:
    int numProcessors;
    int numTasks;
    int *tasks;
public:
    Greedy(const std::string &filename);
    Individual* generateSolution();
    void shuffleTasks();
    ~Greedy();
};;

#endif // GREEDY_H