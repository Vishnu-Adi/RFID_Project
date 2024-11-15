#include "genetic_algorithm.h"
#include <algorithm>
#include <random>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(const Parameters& params) : parameters(params) {}

Solution GeneticAlgorithm::run() {
    GRID_SIZE = parameters.gridSize;
    TOTAL_CELLS = GRID_SIZE * GRID_SIZE;

    int generation = 0;
    auto population = initializePopulation();

    while (!terminationConditionMet(generation)) {
        evaluateFitness(population);
        auto parents = selection(population);
        auto offspring = crossover(parents);
        mutation(offspring);
        population = offspring;
        generation++;
    }

    evaluateFitness(population);
    return *max_element(population.begin(), population.end(),
                        [](const Solution& a, const Solution& b) {
                            return a.fitness < b.fitness;
                        });
}

vector<Solution> GeneticAlgorithm::initializePopulation() {
    vector<Solution> population(parameters.populationSize);
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution d(0.5); // 50% chance of placing a tag

    for (auto& individual : population) {
        individual.positions.resize(parameters.numPositions);
        for (auto& gene : individual.positions) {
            gene = d(gen);
        }
    }
    return population;
}

void GeneticAlgorithm::evaluateFitness(vector<Solution>& population) {
    for (auto& individual : population) {
        individual.fitness = calculateFitness(individual, parameters.gridSize);
    }
}

vector<Solution> GeneticAlgorithm::selection(const vector<Solution>& population) {
    vector<Solution> selected;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, population.size() - 1);

    // Tournament Selection
    for (size_t i = 0; i < population.size(); ++i) {
        auto& individual1 = population[dist(gen)];
        auto& individual2 = population[dist(gen)];
        selected.push_back(individual1.fitness > individual2.fitness ? individual1 : individual2);
    }
    return selected;
}

vector<Solution> GeneticAlgorithm::crossover(const vector<Solution>& parents) {
    vector<Solution> offspring;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, parameters.numPositions - 1); // Crossover point

    for (size_t i = 0; i < parents.size(); i += 2) {
        Solution parent1 = parents[i];
        Solution parent2 = parents[(i + 1) % parents.size()];
        int crossoverPoint = dist(gen);

        Solution child1 = parent1;
        Solution child2 = parent2;

        // Swap genes after the crossover point
        copy(parent2.positions.begin() + crossoverPoint, parent2.positions.end(),
                  child1.positions.begin() + crossoverPoint);
        copy(parent1.positions.begin() + crossoverPoint, parent1.positions.end(),
                  child2.positions.begin() + crossoverPoint);

        offspring.push_back(child1);
        offspring.push_back(child2);
    }
    return offspring;
}

void GeneticAlgorithm::mutation(vector<Solution>& offspring) {
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution mutationChance(parameters.mutationRate);

    for (auto& individual : offspring) {
        for (auto& gene : individual.positions) {
            if (mutationChance(gen)) {
                gene = !gene; // Flip the gene
            }
        }
    }
}

bool GeneticAlgorithm::terminationConditionMet(int generation) {
    return generation >= parameters.maxGenerations;
}