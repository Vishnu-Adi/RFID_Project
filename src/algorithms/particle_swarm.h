// File: src/algorithms/particle_swarm.h

#ifndef PARTICLE_SWARM_H
#define PARTICLE_SWARM_H

#include "../utils/utils.h"
#include "../config/config.h"
#include <vector>

class ParticleSwarmOptimization {
public:
    ParticleSwarmOptimization(const Parameters& params);
    Particle run(); // Executes the PSO and returns the best particle found

private:
    Parameters parameters;
    std::vector<Particle> swarm;
    Particle globalBest;

    void initializeSwarm();
    void evaluateFitness();
    void updateVelocities();
    void updatePositions();
    bool terminationConditionMet(int iteration);

    // Helper method to initialize globalBest
    void updateGlobalBest();
};

#endif // PARTICLE_SWARM_H