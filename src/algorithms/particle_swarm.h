#ifndef PARTICLE_SWARM_H
#define PARTICLE_SWARM_H

#include "../utils/utils.h"
#include "../config/config.h"
#include <vector>

using namespace std;
class ParticleSwarmOptimization {
public:
    ParticleSwarmOptimization(const Parameters& params);
    Particle run(); 

private:
    Parameters parameters;
    vector<Particle> swarm;
    Particle globalBest;

    void initializeSwarm();
    void evaluateFitness();
    void updateVelocities();
    void updatePositions();
    bool terminationConditionMet(int iteration);


    void updateGlobalBest();
};

#endif 