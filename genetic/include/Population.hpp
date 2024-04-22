#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include ".\Individual.hpp"


class Population {
private:
    int populationSize;
    Individual **individuals;

public:
    Population(int populationSize, const std::string &filename);
    void printPopulation();
    void selectIndividuals(float selectPercent); // Steady state selection
    ~Population();
};

#endif // POPULATION_HPP