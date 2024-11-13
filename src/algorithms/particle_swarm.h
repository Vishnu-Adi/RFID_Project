#ifndef PARTICLE_SWARM_H
#define PARTICLE_SWARM_H

#include "../utils/utils.h"
#include "../config/config.h"
#include <vector>

class ParticleSwarmOptimization {
public:
    ParticleSwarmOptimization(const Parameters& params);
    Particle run();

private:
    Parameters parameters;
    std::vector<Particle> swarm;
    Particle globalBest;

    void initializeSwarm();
    void evaluateFitness();
    void updateVelocities();
    void updatePositions();
    bool terminationConditionMet(int iteration);
};

#endif // PARTICLE_SWARM_H