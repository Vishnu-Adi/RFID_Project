#ifndef UTILS_H
#define UTILS_H

#include <vector>

// Solution struct for GA
struct Solution {
    std::vector<int> positions; // Binary representation of tag placements
    double fitness;
};

// Particle struct for PSO
struct Particle {
    std::vector<double> position; // Continuous positions
    std::vector<double> velocity;
    std::vector<double> bestPosition;
    double fitness;
    double bestFitness;
};

// Function declarations
double computeCoverage(const Solution& solution);
double computeCost(const Solution& solution);
double calculateFitness(const Solution& solution);

double computeCoverage(const std::vector<double>& position);
double computeCost(const std::vector<double>& position);
double calculateFitness(const std::vector<double>& position);

#endif // UTILS_H