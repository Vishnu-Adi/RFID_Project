// File: src/utils/utils.h

#ifndef UTILS_H
#define UTILS_H

#include <vector>

// Extern declarations for dynamic grid size
extern int GRID_SIZE;
extern int TOTAL_CELLS;

// Solution struct for GA
struct Solution {
    std::vector<int> positions; // Binary representation of tag placements
    double fitness;
};

// Particle struct for PSO
struct Particle {
    std::vector<double> position;      // Continuous positions
    std::vector<double> velocity;
    std::vector<double> bestPosition;
    double fitness;
    double bestFitness;
};

// Result struct for storing test results
struct Result {
    double fitness;
    int generations; // For GA
    int iterations;  // For PSO
    double executionTime;
};

// Function declarations
std::vector<std::pair<int, int>> getNeighbors(int x, int y, int gridSize);

double computeCoverage(const Solution& solution, int gridSize);
double computeCost(const Solution& solution);
double calculateFitness(const Solution& solution, int gridSize);

double computeCoverage(const std::vector<double>& position, int gridSize);
double computeCost(const std::vector<double>& position);
double calculateFitness(const std::vector<double>& position, int gridSize);

#endif // UTILS_H