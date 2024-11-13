// File: src/algorithms/genetic_algorithm.h

#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "../utils/utils.h"
#include "../config/config.h"
#include <vector>

class GeneticAlgorithm {
public:
    GeneticAlgorithm(const Parameters& params);
    Solution run(); // Executes the GA and returns the best solution found

private:
    Parameters parameters;

    std::vector<Solution> initializePopulation();
    void evaluateFitness(std::vector<Solution>& population);
    std::vector<Solution> selection(const std::vector<Solution>& population);
    std::vector<Solution> crossover(const std::vector<Solution>& parents);
    void mutation(std::vector<Solution>& offspring);
    bool terminationConditionMet(int generation);
};

#endif // GENETIC_ALGORITHM_H