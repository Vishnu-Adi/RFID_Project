#ifndef UTILS_H
#define UTILS_H

#include <vector>

struct Solution {
    std::vector<int> positions;
    double fitness;
};

struct Particle {
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> bestPosition;
    double fitness;
    double bestFitness;
};

struct Parameters {
    int populationSize;
    int maxGenerations;
    int swarmSize;
    int maxIterations;
    // Add other parameters as needed
};

double calculateFitness(const Solution& solution);
double calculateFitness(const std::vector<double>& position);

#endif // UTILS_H