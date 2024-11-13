# File: visualize_results.py

import pandas as pd
import matplotlib.pyplot as plt

def visualize_results():
    # Read the GA and PSO result CSV files
    ga_results = pd.read_csv('ga_results.csv')
    pso_results = pd.read_csv('pso_results.csv')
    
    # Ensure that the 'GridSize' column is of integer type
    ga_results['GridSize'] = ga_results['GridSize'].astype(int)
    pso_results['GridSize'] = pso_results['GridSize'].astype(int)
    
    # Sort the dataframes by GridSize
    ga_results.sort_values('GridSize', inplace=True)
    pso_results.sort_values('GridSize', inplace=True)
    
    # Plot Fitness vs GridSize
    plt.figure(figsize=(10, 6))
    plt.plot(ga_results['GridSize'], ga_results['Fitness'], marker='o', label='GA Fitness')
    plt.plot(pso_results['GridSize'], pso_results['Fitness'], marker='s', label='PSO Fitness')
    plt.title('Average Fitness vs Grid Size')
    plt.xlabel('Grid Size')
    plt.ylabel('Average Fitness')
    plt.legend()
    plt.grid(True)
    plt.savefig('fitness_vs_grid_size.png')
    plt.show()
    
    # Plot Execution Time vs GridSize
    plt.figure(figsize=(10, 6))
    plt.plot(ga_results['GridSize'], ga_results['Time'], marker='o', label='GA Execution Time')
    plt.plot(pso_results['GridSize'], pso_results['Time'], marker='s', label='PSO Execution Time')
    plt.title('Average Execution Time vs Grid Size')
    plt.xlabel('Grid Size')
    plt.ylabel('Execution Time (seconds)')
    plt.legend()
    plt.grid(True)
    plt.savefig('time_vs_grid_size.png')
    plt.show()
    
    # Plot Fitness vs Execution Time
    plt.figure(figsize=(10, 6))
    plt.plot(ga_results['Time'], ga_results['Fitness'], marker='o', label='GA')
    plt.plot(pso_results['Time'], pso_results['Fitness'], marker='s', label='PSO')
    plt.title('Average Fitness vs Execution Time')
    plt.xlabel('Execution Time (seconds)')
    plt.ylabel('Average Fitness')
    plt.legend()
    plt.grid(True)
    plt.savefig('fitness_vs_time.png')
    plt.show()
    
    # Combined bar chart for fitness comparison
    width = 0.35  # Width of the bars
    grid_sizes = ga_results['GridSize']
    x = range(len(grid_sizes))
    
    plt.figure(figsize=(10, 6))
    plt.bar([i - width/2 for i in x], ga_results['Fitness'], width=width, label='GA Fitness')
    plt.bar([i + width/2 for i in x], pso_results['Fitness'], width=width, label='PSO Fitness')
    plt.title('Average Fitness Comparison')
    plt.xlabel('Grid Size')
    plt.ylabel('Average Fitness')
    plt.xticks(x, grid_sizes)
    plt.legend()
    plt.grid(True)
    plt.savefig('fitness_comparison.png')
    plt.show()
    
    # Combined bar chart for execution time comparison
    plt.figure(figsize=(10, 6))
    plt.bar([i - width/2 for i in x], ga_results['Time'], width=width, label='GA Time')
    plt.bar([i + width/2 for i in x], pso_results['Time'], width=width, label='PSO Time')
    plt.title('Execution Time Comparison')
    plt.xlabel('Grid Size')
    plt.ylabel('Execution Time (seconds)')
    plt.xticks(x, grid_sizes)
    plt.legend()
    plt.grid(True)
    plt.savefig('time_comparison.png')
    plt.show()

if __name__ == '__main__':
    visualize_results()