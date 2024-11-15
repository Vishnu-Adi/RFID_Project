#include "particle_swarm.h"
#include <algorithm>
#include <random>
#include <limits>

using namespace std;

ParticleSwarmOptimization::ParticleSwarmOptimization(const Parameters& params)
    : parameters(params) {}

Particle ParticleSwarmOptimization::run() {
    GRID_SIZE = parameters.gridSize;
    TOTAL_CELLS = GRID_SIZE * GRID_SIZE;

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
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> posDis(parameters.positionMin, parameters.positionMax);
    uniform_real_distribution<> velDis(-parameters.velocityMax, parameters.velocityMax);

    swarm.resize(parameters.swarmSize);
    globalBest.fitness = numeric_limits<double>::lowest();

    for (auto& particle : swarm) {
        particle.position.resize(parameters.numDimensions);
        particle.velocity.resize(parameters.numDimensions);
        particle.bestPosition.resize(parameters.numDimensions);

        for (int d = 0; d < parameters.numDimensions; ++d) {
            particle.position[d] = posDis(gen);
            particle.velocity[d] = velDis(gen);
            particle.bestPosition[d] = particle.position[d];
        }
        particle.fitness = calculateFitness(particle.position, parameters.gridSize);
        particle.bestFitness = particle.fitness;

        if (particle.fitness > globalBest.fitness) {
            globalBest = particle;
        }
    }
}

void ParticleSwarmOptimization::evaluateFitness() {
    for (auto& particle : swarm) {
        particle.fitness = calculateFitness(particle.position, parameters.gridSize);

        if (particle.fitness > particle.bestFitness) {
            particle.bestFitness = particle.fitness;
            particle.bestPosition = particle.position;
        }

        if (particle.fitness > globalBest.fitness) {
            globalBest = particle;
        }
    }
}

void ParticleSwarmOptimization::updateVelocities() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> randDis(0.0, 1.0);

    for (auto& particle : swarm) {
        for (int d = 0; d < parameters.numDimensions; ++d) {
            double r1 = randDis(gen);
            double r2 = randDis(gen);

            particle.velocity[d] = parameters.inertiaWeight * particle.velocity[d]
                + parameters.cognitiveCoefficient * r1 * (particle.bestPosition[d] - particle.position[d])
                + parameters.socialCoefficient * r2 * (globalBest.position[d] - particle.position[d]);

            // Clamp velocity
            if (particle.velocity[d] > parameters.velocityMax) {
                particle.velocity[d] = parameters.velocityMax;
            } else if (particle.velocity[d] < -parameters.velocityMax) {
                particle.velocity[d] = -parameters.velocityMax;
            }
        }
    }
}

void ParticleSwarmOptimization::updatePositions() {
    for (auto& particle : swarm) {
        for (int d = 0; d < parameters.numDimensions; ++d) {
            particle.position[d] += particle.velocity[d];

            // Clamp position
            if (particle.position[d] > parameters.positionMax) {
                particle.position[d] = parameters.positionMax;
            } else if (particle.position[d] < parameters.positionMin) {
                particle.position[d] = parameters.positionMin;
            }
        }
    }
}

bool ParticleSwarmOptimization::terminationConditionMet(int iteration) {
    return iteration >= parameters.maxIterations;
}