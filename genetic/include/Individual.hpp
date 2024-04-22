#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <iostream>


class Individual {
private:
    int numTasks;
    int numProcessors;
    int fitness;
    int **tasks;

public:
    Individual(int numTasks, int numProcessors, int **tasks);
    void printIndividual();
    int evaluate();
    int getFitness();
    Individual* crossover(Individual* other);
    void sortTasks();
    ~Individual();
};

#endif // INDIVIDUAL_HPP