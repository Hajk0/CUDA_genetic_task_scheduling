#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include ".\Individual.hpp"


class Population {
private:
    int populationSize;
    int freeSpace;
    Individual **individuals;

public:
    Population(int populationSize, const std::string &filename);
    void printPopulation();
    void selectIndividuals(float selectPercent); // Steady state selection
    Individual* randomCrossover();
    void populationCrossover();
    void populationMutation(float individualMutationProbability, float geneMutationProbability);
    void simulateGenerations(int generations, float selectPercent, float mutationProbability, float geneMutationProbability);
    void debug();
    ~Population();
};

#endif // POPULATION_HPP