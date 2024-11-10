#ifndef PARTICLE_SWARM_H
#define PARTICLE_SWARM_H

#include <vector>
#include "../utils/utils.h"

class ParticleSwarmOptimization {
public:
    ParticleSwarmOptimization(const Parameters& params);
    Solution run();

private:
    Parameters parameters;

    void initializeSwarm();
    void updateVelocities();
    void updatePositions();
    void evaluateFitness();
    bool terminationConditionMet(int iteration);

    std::vector<Particle> swarm;
    Solution globalBest;
};

#endif // PARTICLE_SWARM_H