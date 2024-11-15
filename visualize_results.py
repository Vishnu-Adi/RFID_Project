import pandas as pd
import matplotlib.pyplot as plt

def visualize_results():

    ga_results = pd.read_csv('ga_results.csv')
    pso_results = pd.read_csv('pso_results.csv')
    

    ga_results['GridSize'] = ga_results['GridSize'].astype(int)
    pso_results['GridSize'] = pso_results['GridSize'].astype(int)
    

    ga_results.sort_values('GridSize', inplace=True)
    pso_results.sort_values('GridSize', inplace=True)
    
    
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
    

    width = 0.35  
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