#include "utils.h"
#include <cmath>
#include <vector>

const int GRID_SIZE = 10; // 10x10 grid
const int TOTAL_CELLS = GRID_SIZE * GRID_SIZE;
const std::vector<std::pair<int, int>> READER_POSITIONS = {
    {0, 0}, {0, GRID_SIZE - 1}, {GRID_SIZE - 1, 0}, {GRID_SIZE - 1, GRID_SIZE - 1}
};

// Helper function to get neighboring cells
std::vector<std::pair<int, int>> getNeighbors(int x, int y) {
    std::vector<std::pair<int, int>> neighbors;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
                neighbors.emplace_back(nx, ny);
            }
        }
    }
    return neighbors;
}

// GA: Compute coverage based on tag positions
double computeCoverage(const Solution& solution) {
    // Grid to mark covered cells
    std::vector<std::vector<bool>> coverageGrid(GRID_SIZE, std::vector<bool>(GRID_SIZE, false));

    // Mark cells covered by tags
    for (int i = 0; i < solution.positions.size(); ++i) {
        if (solution.positions[i]) {
            int x = i % GRID_SIZE;
            int y = i / GRID_SIZE;
            auto neighbors = getNeighbors(x, y);
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

    return static_cast<double>(coveredCells) / TOTAL_CELLS; // Coverage ratio between 0 and 1
}

// GA: Compute cost based on number of tags used
double computeCost(const Solution& solution) {
    int tagsUsed = 0;
    for (int tagPlaced : solution.positions) {
        if (tagPlaced) {
            ++tagsUsed;
        }
    }
    // Assume cost per tag is 1 unit
    return static_cast<double>(tagsUsed);
}

// PSO: Compute coverage for continuous positions
double computeCoverage(const std::vector<double>& position) {
    // Interpret the continuous positions as probabilities of placing a tag
    // Place a tag if the value is greater than 0.5
    std::vector<int> tagPositions(position.size());
    for (int i = 0; i < position.size(); ++i) {
        tagPositions[i] = position[i] > 0.5 ? 1 : 0;
    }

    // Create a temporary Solution object to reuse GA's computeCoverage
    Solution tempSolution{tagPositions, 0.0};
    return computeCoverage(tempSolution);
}

// PSO: Compute cost similar to GA
double computeCost(const std::vector<double>& position) {
    // Interpret the continuous positions as probabilities of placing a tag
    // Place a tag if the value is greater than 0.5
    int tagsUsed = 0;
    for (double val : position) {
        if (val > 0.5) {
            ++tagsUsed;
        }
    }
    return static_cast<double>(tagsUsed);
}

double calculateFitness(const Solution& solution) {
    double coverage = computeCoverage(solution);
    double cost = computeCost(solution);

    if (cost == 0.0) {
        return 0.0;
    }

    // Fitness function: maximize coverage and minimize cost
    return coverage / cost;
}

double calculateFitness(const std::vector<double>& position) {
    double coverage = computeCoverage(position);
    double cost = computeCost(position);

    if (cost == 0.0) {
        return 0.0;
    }

    // Fitness function: maximize coverage and minimize cost
    return coverage / cost;
}