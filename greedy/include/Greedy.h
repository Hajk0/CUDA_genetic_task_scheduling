#include <iostream>
#include <fstream>
#include <string>

class Greedy
{
private:
    int numProcessors;
    int numTasks;
    int *tasks;
public:
    Greedy(const std::string &filename);
    int* generateSolution();
    ~Greedy();
};;
