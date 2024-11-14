#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "../algorithms/genetic_algorithm.h"
#include "../algorithms/particle_swarm.h"
#include "../config/config.h"
#include "../utils/utils.h"
#include <vector>

using namespace std;
class TestRunner {
public:
    TestRunner();
    void runTests();

private:
    void testGA(const Parameters& params, Result& result);
    void testPSO(const Parameters& params, Result& result);
    void printResults();

    vector<Parameters> gaTestCases;
    vector<Parameters> psoTestCases;
    vector<Result> gaResults;
    vector<Result> psoResults;

    void initializeTestCases();

    // Helper method to calculate standard deviation
    double calculateStdDev(const vector<double>& values, double mean);
};

#endif 