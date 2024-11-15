#ifndef CONFIG_H
#define CONFIG_H

struct Parameters {
    // Genetic Algorithm parameters
    int populationSize;
    int numPositions;      // Number of potential tag positions (grid cells)
    double mutationRate;
    int maxGenerations;

    // Particle Swarm Optimization parameters
    int swarmSize;
    int numDimensions;     // Should match numPositions
    int maxIterations;
    double positionMin;
    double positionMax;
    double velocityMax;
    double inertiaWeight;
    double cognitiveCoefficient;
    double socialCoefficient;

    // Common parameter
    int gridSize;          // Grid size for dynamic grids
};

#endif 