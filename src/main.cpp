#include <iostream>
#include <vector>
#include "algorithms/genetic_algorithm.h"
#include "algorithms/particle_swarm.h"
#include "config/config.h"
#include "utils/utils.h"
#include "tests/test_runner.h"

using namespace std;

void displaySolution(const Solution& solution, int gridSize) {
    cout << "Tag Positions (1 indicates a tag):" << endl;
    for (int i = 0; i < solution.positions.size(); ++i) {
        cout << solution.positions[i] << " ";
        if ((i + 1) % gridSize == 0) {
            cout << endl;
        }
    }
    cout << "Fitness: " << solution.fitness << endl;
}

void displayParticle(const Particle& particle, int gridSize) {
    cout << "Tag Positions (values > 0.5 indicate a tag):" << endl;
    for (int i = 0; i < particle.position.size(); ++i) {
        cout << (particle.position[i] > 0.5 ? 1 : 0) << " ";
        if ((i + 1) % gridSize == 0) {
            cout << endl;
        }
    }
    cout << "Fitness: " << particle.fitness << endl;
}

int main() {
    cout << "Select mode:\n";
    cout << "1. Run Optimization\n";
    cout << "2. Run Tests\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Parameters params = {
            // GA parameters
            50,     // populationSize
            100,    // numPositions (default 10x10 grid)
            0.05,   // mutationRate
            50,     // maxGenerations
            // PSO parameters
            50,     // swarmSize
            100,    // numDimensions (default 10x10 grid)
            50,     // maxIterations
            0.0,    // positionMin
            1.0,    // positionMax
            0.1,    // velocityMax
            0.729,  // inertiaWeight
            1.49445,// cognitiveCoefficient
            1.49445,// socialCoefficient
            // Common parameter
            10      // gridSize
        };

        cout << "Select optimization method:\n";
        cout << "1. Genetic Algorithm\n";
        cout << "2. Particle Swarm Optimization\n";
        int optChoice;
        cin >> optChoice;

        if (optChoice == 1) {
            GeneticAlgorithm ga(params);
            Solution bestSolution = ga.run();
            cout << "\nBest Solution (GA):" << endl;
            displaySolution(bestSolution, params.gridSize);
        } else if (optChoice == 2) {
            ParticleSwarmOptimization pso(params);
            Particle bestParticle = pso.run();
            cout << "\nBest Particle (PSO):" << endl;
            displayParticle(bestParticle, params.gridSize);
        } else {
            cout << "Invalid choice." << endl;
        }
    } else if (choice == 2) {
        TestRunner tester;
        tester.runTests();
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}