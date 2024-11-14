#include "test_runner.h"
#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>

TestRunner::TestRunner() {
    initializeTestCases();
}

using namespace std;
void TestRunner::initializeTestCases() {
    // Define test cases for GA
    for (int gridSize = 5; gridSize <= 15; gridSize += 5) {
        Parameters params;
        params.gridSize = gridSize;
        params.populationSize = 50;
        params.numPositions = gridSize * gridSize;
        params.mutationRate = 0.05;
        params.maxGenerations = 100;

        gaTestCases.push_back(params);
    }

    // Define test cases for PSO
    for (int gridSize = 5; gridSize <= 15; gridSize += 5) {
        Parameters params;
        params.gridSize = gridSize;
        params.swarmSize = 50;
        params.numDimensions = gridSize * gridSize;
        params.maxIterations = 100;
        params.positionMin = 0.0;
        params.positionMax = 1.0;
        params.velocityMax = 0.1;
        params.inertiaWeight = 0.729;
        params.cognitiveCoefficient = 1.49445;
        params.socialCoefficient = 1.49445;

        psoTestCases.push_back(params);
    }
}

void TestRunner::runTests() {
    const int runsPerTest = 5;

    cout << "Running GA Test Cases..." << endl;
    for (auto& params : gaTestCases) {
        double totalFitness = 0.0;
        double totalTime = 0.0;
        vector<double> fitnesses;

        for (int i = 0; i < runsPerTest; i++) {
            Result result;
            testGA(params, result);
            totalFitness += result.fitness;
            totalTime += result.executionTime;
            fitnesses.push_back(result.fitness);
        }

        double avgFitness = totalFitness / runsPerTest;
        double avgTime = totalTime / runsPerTest;
        double stddevFitness = calculateStdDev(fitnesses, avgFitness);

        Result avgResult;
        avgResult.fitness = avgFitness;
        avgResult.executionTime = avgTime;
        avgResult.generations = params.maxGenerations; // Or average if dynamic
        gaResults.push_back(avgResult);

        cout << "GA GridSize: " << params.gridSize << ", Avg Fitness: " << avgFitness
                  << ", StdDev: " << stddevFitness << ", Avg Time: " << avgTime << "s\n";
    }

    cout << "\nRunning PSO Test Cases..." << endl;
    for (auto& params : psoTestCases) {
        double totalFitness = 0.0;
        double totalTime = 0.0;
        vector<double> fitnesses;

        for (int i = 0; i < runsPerTest; i++) {
            Result result;
            testPSO(params, result);
            totalFitness += result.fitness;
            totalTime += result.executionTime;
            fitnesses.push_back(result.fitness);
        }

        double avgFitness = totalFitness / runsPerTest;
        double avgTime = totalTime / runsPerTest;
        double stddevFitness = calculateStdDev(fitnesses, avgFitness);

        Result avgResult;
        avgResult.fitness = avgFitness;
        avgResult.executionTime = avgTime;
        avgResult.iterations = params.maxIterations;
        psoResults.push_back(avgResult);

        cout << "PSO GridSize: " << params.gridSize << ", Avg Fitness: " << avgFitness
                  << ", StdDev: " << stddevFitness << ", Avg Time: " << avgTime << "s\n";
    }

    // Optionally write results to files
    printResults();
}

double TestRunner::calculateStdDev(const vector<double>& values, double mean) {
    double sumSqDiff = 0.0;
    for (double val : values) {
        sumSqDiff += (val - mean) * (val - mean);
    }
    return sqrt(sumSqDiff / values.size());
}

void TestRunner::testGA(const Parameters& params, Result& result) {
    GRID_SIZE = params.gridSize;
    TOTAL_CELLS = GRID_SIZE * GRID_SIZE;

    GeneticAlgorithm ga(params);
    auto start = chrono::high_resolution_clock::now();
    Solution bestSolution = ga.run();
    auto end = chrono::high_resolution_clock::now();

    result.fitness = bestSolution.fitness;
    result.executionTime = chrono::duration<double>(end - start).count();
    result.generations = params.maxGenerations;
}

void TestRunner::testPSO(const Parameters& params, Result& result) {
    GRID_SIZE = params.gridSize;
    TOTAL_CELLS = GRID_SIZE * GRID_SIZE;

    ParticleSwarmOptimization pso(params);
    auto start = chrono::high_resolution_clock::now();
    Particle bestParticle = pso.run();
    auto end = chrono::high_resolution_clock::now();

    result.fitness = bestParticle.fitness;
    result.executionTime = chrono::duration<double>(end - start).count();
    result.iterations = params.maxIterations;
}

void TestRunner::printResults() {
    // Write GA results to CSV file
    ofstream gaOut("ga_results.csv");
    gaOut << "GridSize,Fitness,Time\n";
    for (size_t i = 0; i < gaResults.size(); ++i) {
        gaOut << gaTestCases[i].gridSize << ","
              << gaResults[i].fitness << ","
              << gaResults[i].executionTime << "\n";
    }
    gaOut.close();

    // Write PSO results to CSV file
    ofstream psoOut("pso_results.csv");
    psoOut << "GridSize,Fitness,Time\n";
    for (size_t i = 0; i < psoResults.size(); ++i) {
        psoOut << psoTestCases[i].gridSize << ","
               << psoResults[i].fitness << ","
               << psoResults[i].executionTime << "\n";
    }
    psoOut.close();
}