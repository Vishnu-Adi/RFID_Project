#ifndef CONFIG_H
#define CONFIG_H

struct Parameters {
    // Genetic Algorithm parameters
    int populationSize;
    int numPositions;
    double mutationRate;
    int maxGenerations;

    // Particle Swarm Optimization parameters
    int swarmSize;
    int numDimensions;
    int maxIterations;
    double positionMin;
    double positionMax;
    double velocityMax;
    double inertiaWeight;
    double cognitiveCoefficient;
    double socialCoefficient;
};

#endif // CONFIG_H