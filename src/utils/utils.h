// File: src/utils/utils.h

#ifndef UTILS_H
#define UTILS_H

#include <vector>
using namespace std;

extern int GRID_SIZE;
extern int TOTAL_CELLS;

// Solution struct for GA
struct Solution {
    vector<int> positions; // Binary representation of tag placements
    double fitness;
};

// Particle struct for PSO
struct Particle {
    vector<double> position;      // Continuous positions
    vector<double> velocity;
    vector<double> bestPosition;
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
vector<pair<int, int>> getNeighbors(int x, int y, int gridSize);

double computeCoverage(const Solution& solution, int gridSize);
double computeCost(const Solution& solution);
double calculateFitness(const Solution& solution, int gridSize);

double computeCoverage(const vector<double>& position, int gridSize);
double computeCost(const vector<double>& position);
double calculateFitness(const vector<double>& position, int gridSize);

#endif // UTILS_H