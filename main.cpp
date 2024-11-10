#include <iostream>
#include "algorithms/genetic_algorithm.h"
#include "algorithms/particle_swarm.h"
#include "config/config.h"

int main() {
    Parameters params = DEFAULT_PARAMETERS;

    std::cout << "Select optimization method:\n";
    std::cout << "1. Genetic Algorithm\n";
    std::cout << "2. Particle Swarm Optimization\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        GeneticAlgorithm ga(params);
        Solution bestSolution = ga.run();
        std::cout << "Best fitness (GA): " << bestSolution.fitness << std::endl;
    } else if (choice == 2) {
        ParticleSwarmOptimization pso(params);
        Solution bestSolution = pso.run();
        std::cout << "Best fitness (PSO): " << bestSolution.fitness << std::endl;
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}