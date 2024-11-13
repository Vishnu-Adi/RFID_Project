// File: src/utils/utils.cpp

#include "utils.h"
#include <cmath>
#include <vector>

int GRID_SIZE = 10; // Default value
int TOTAL_CELLS = GRID_SIZE * GRID_SIZE;

// Helper function to get neighboring cells
std::vector<std::pair<int, int>> getNeighbors(int x, int y, int gridSize) {
    std::vector<std::pair<int, int>> neighbors;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize) {
                neighbors.emplace_back(nx, ny);
            }
        }
    }
    return neighbors;
}

// GA: Compute coverage based on tag positions
double computeCoverage(const Solution& solution, int gridSize) {
    // Grid to mark covered cells
    std::vector<std::vector<bool>> coverageGrid(gridSize, std::vector<bool>(gridSize, false));

    // Mark cells covered by tags
    for (int i = 0; i < solution.positions.size(); ++i) {
        if (solution.positions[i]) {
            int x = i % gridSize;
            int y = i / gridSize;
            auto neighbors = getNeighbors(x, y, gridSize);
            for (auto& cell : neighbors) {
                coverageGrid[cell.second][cell.first] = true;
            }
        }
    }

    // Calculate coverage ratio
    int coveredCells = 0;
    for (const auto& row : coverageGrid) {
        for (bool covered : row) {
            if (covered) {
                ++coveredCells;
            }
        }
    }

    return static_cast<double>(coveredCells) / (gridSize * gridSize); // Coverage ratio between 0 and 1
}

// GA: Compute cost based on number of tags used
double computeCost(const Solution& solution) {
    int tagsUsed = 0;
    for (int tagPlaced : solution.positions) {
        if (tagPlaced) {
            ++tagsUsed;
        }
    }
    return static_cast<double>(tagsUsed); // Cost is proportional to tags used
}

// PSO: Compute coverage for continuous positions
double computeCoverage(const std::vector<double>& position, int gridSize) {
    // Interpret the continuous positions as probabilities of placing a tag
    // Place a tag if the value is greater than 0.5
    std::vector<int> tagPositions(position.size());
    for (int i = 0; i < position.size(); ++i) {
        tagPositions[i] = position[i] > 0.5 ? 1 : 0;
    }

    // Create a temporary Solution object to reuse GA's computeCoverage
    Solution tempSolution{tagPositions, 0.0};
    return computeCoverage(tempSolution, gridSize);
}

// PSO: Compute cost similar to GA
double computeCost(const std::vector<double>& position) {
    int tagsUsed = 0;
    for (double posValue : position) {
        if (posValue > 0.5) {
            ++tagsUsed;
        }
    }
    return static_cast<double>(tagsUsed);
}

double calculateFitness(const Solution& solution, int gridSize) {
    double coverage = computeCoverage(solution, gridSize);
    double cost = computeCost(solution);
    if (cost == 0.0) {
        return 0.0;
    }
    return coverage / cost;
}

double calculateFitness(const std::vector<double>& position, int gridSize) {
    double coverage = computeCoverage(position, gridSize);
    double cost = computeCost(position);
    if (cost == 0.0) {
        return 0.0;
    }
    return coverage / cost;
}