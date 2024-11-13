// File: src/tests/test_runner.h

#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "../algorithms/genetic_algorithm.h"
#include "../algorithms/particle_swarm.h"
#include "../config/config.h"
#include "../utils/utils.h"
#include <vector>

class TestRunner {
public:
    TestRunner();
    void runTests();

private:
    void testGA(const Parameters& params, Result& result);
    void testPSO(const Parameters& params, Result& result);
    void printResults();

    std::vector<Parameters> gaTestCases;
    std::vector<Parameters> psoTestCases;
    std::vector<Result> gaResults;
    std::vector<Result> psoResults;

    void initializeTestCases();

    // Helper method to calculate standard deviation
    double calculateStdDev(const std::vector<double>& values, double mean);
};

#endif // TEST_RUNNER_H