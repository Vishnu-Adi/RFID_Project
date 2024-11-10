#include "particle_swarm.h"
#include <algorithm>
#include <random>

ParticleSwarmOptimization::ParticleSwarmOptimization(const Parameters& params)
    : parameters(params) {}

Solution ParticleSwarmOptimization::run() {
    int iteration = 0;
    initializeSwarm();
    evaluateFitness();

    while (!terminationConditionMet(iteration)) {
        updateVelocities();
        updatePositions();
        evaluateFitness();
        iteration++;
    }

    return globalBest;
}

void ParticleSwarmOptimization::initializeSwarm() {
    // Implementation to initialize the swarm
}

void ParticleSwarmOptimization::updateVelocities() {
    // Update velocities of particles
}

void ParticleSwarmOptimization::updatePositions() {
    // Update positions of particles
}

void ParticleSwarmOptimization::evaluateFitness() {
    // Evaluate fitness and update global best
    for (auto& particle : swarm) {
        particle.fitness = calculateFitness(particle.position);
        if (particle.fitness > particle.bestFitness) {
            particle.bestFitness = particle.fitness;
            particle.bestPosition = particle.position;
        }
        if (particle.fitness > globalBest.fitness) {
            globalBest = { particle.position, particle.fitness };
        }
    }
}

bool ParticleSwarmOptimization::terminationConditionMet(int iteration) {
    return iteration >= parameters.maxIterations;
}