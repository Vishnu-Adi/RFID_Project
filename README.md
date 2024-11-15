
# RFID TAG PLACEMENT OPTIMIZATION

This project focuses on optimizing the placement of RFID tags within a grid-based environment to maximize coverage while minimizing deployment costs. Two optimization strategies are implemented: Genetic Algorithm (GA) and Particle Swarm Optimization (PSO).

## Dependencies

### C++ Dependencies

- **Compiler**: GCC or Clang with C++11 support.
- **Libraries**: No external C++ libraries are required beyond the standard library.

### Python Dependencies

- **Python 3.x**
- **Libraries**:
  - `pandas`
    - `matplotlib`

    ### Install Python dependencies using `pip`:

         pip install pandas matplotlib

# Compilation Instructions:

### Using Command Line
Navigate to the project root directory and execute the following command:

         g++ -std=c++11 src/main.cpp src/algorithms/genetic_algorithm.cpp src/algorithms/particle_swarm.cpp src/utils/utils.cpp src/tests/test_runner.cpp -o optimization_app

or Using clangd++:

         clang++ -std=c++11 src/main.cpp src/algorithms/genetic_algorithm.cpp src/algorithms/particle_swarm.cpp src/utils/utils.cpp src/tests/test_runner.cpp -o optimization_app


### Running the Application
After successful compilation, execute the application:

         ./optimization_app


# Application Modes
## Run Optimization:

         Select Optimization Method: Choose between Genetic Algorithm (GA) or Particle Swarm Optimization (PSO).
         View Results: The best solution found by the selected algorithm will be displayed, including tag positions and fitness score.

## Run Tests:

        Executes predefined test cases for both GA and PSO across different grid sizes.
         Results are saved in ga_results.csv and pso_results.csv.
         Generate visualizations by running the visualize_results.py script.


# Visualization - Generating Plots
## script:
         python visualize_results.py or python3 visualize_results.py

### Project Structure
         RFID_Tag_Placement_Optimization/
         ├── src/
         │   ├── algorithms/
         │   │   ├── genetic_algorithm.h
         │   │   ├── genetic_algorithm.cpp
         │   │   ├── particle_swarm.h
         │   │   └── particle_swarm.cpp
         │   ├── config/
         │   │   └── config.h
         │   ├── tests/
         │   │   ├── test_runner.h
         │   │   └── test_runner.cpp
         │   ├── utils/
         │   │   ├── utils.h
         │   │   └── utils.cpp
         │   └── main.cpp
         ├
         │── visualize_results.py
         |
         ├── README.md
         ├── ga_results.csv
         ├── pso_results.csv
         └── plots/
             ├── fitness_vs_grid_size.png
                 ├── time_vs_grid_size.png
                     ├── fitness_vs_time.png
                         ├── fitness_comparison.png
                             └── time_comparison.png





