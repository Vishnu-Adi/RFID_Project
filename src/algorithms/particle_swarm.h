#ifndef PARTICLE_SWARM_H
#define PARTICLE_SWARM_H

#include "../utils/utils.h"
#include "../config/config.h"
#include <vector>

using namespace std;
class ParticleSwarmOptimization {
public:
    ParticleSwarmOptimization(const Parameters& params);
    Particle run(); // Executes the PSO and returns the best particle found

private:
    Parameters parameters;
    vector<Particle> swarm;
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