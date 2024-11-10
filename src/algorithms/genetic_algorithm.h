#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>
#include "../utils/utils.h"

class GeneticAlgorithm {
public:
    GeneticAlgorithm(const Parameters& params);
    Solution run();

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