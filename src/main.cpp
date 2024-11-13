#include <iostream>
#include <vector>
#include "algorithms/genetic_algorithm.h"
#include "algorithms/particle_swarm.h"
#include "config/config.h"
#include "utils/utils.h"

void displaySolution(const Solution& solution) {
    std::cout << "Tag Positions (1 indicates a tag):" << std::endl;
    for (int i = 0; i < solution.positions.size(); ++i) {
        std::cout << solution.positions[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << "Fitness: " << solution.fitness << std::endl;
}

void displayParticle(const Particle& particle) {
    std::cout << "Tag Positions (values > 0.5 indicate a tag):" << std::endl;
    for (int i = 0; i < particle.position.size(); ++i) {
        std::cout << (particle.position[i] > 0.5 ? 1 : 0) << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << "Fitness: " << particle.fitness << std::endl;
}

int main() {
    Parameters params = {
        // GA parameters
        50,     // populationSize
        100,    // numPositions (10x10 grid)
        0.05,   // mutationRate
        50,     // maxGenerations

        // PSO parameters
        50,     // swarmSize
        100,    // numDimensions (10x10 grid)
        50,     // maxIterations
        0.0,    // positionMin
        1.0,    // positionMax
        0.1,    // velocityMax
        0.729,  // inertiaWeight
        1.49445,// cognitiveCoefficient
        1.49445 // socialCoefficient
    };

    std::cout << "Select optimization method:\n";
    std::cout << "1. Genetic Algorithm\n";
    std::cout << "2. Particle Swarm Optimization\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        GeneticAlgorithm ga(params);
        Solution bestSolution = ga.run();
        std::cout << "\nBest Solution (GA):" << std::endl;
        displaySolution(bestSolution);
    } else if (choice == 2) {
        ParticleSwarmOptimization pso(params);
        Particle bestParticle = pso.run();
        std::cout << "\nBest Particle (PSO):" << std::endl;
        displayParticle(bestParticle);
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}