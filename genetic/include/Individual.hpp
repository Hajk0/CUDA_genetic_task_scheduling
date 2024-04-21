#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <iostream>


class Individual {
private:
    int numTasks;
    int numProcessors;
    int *tasks;
    int *solution;

public:
    Individual(int numTasks, int numProcessors, int *tasks, int *solution);
};

#endif // INDIVIDUAL_HPP