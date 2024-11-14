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

    vector<Solution> initializePopulation();
    void evaluateFitness(vector<Solution>& population);
    vector<Solution> selection(const vector<Solution>& population);
    vector<Solution> crossover(const vector<Solution>& parents);
    void mutation(vector<Solution>& offspring);
    bool terminationConditionMet(int generation);
};

#endif // GENETIC_ALGORITHM_H