**Travelling Salesman Optimizer**

Written in C, this program uses simulated annealing to approach optimization of the travelling salesman problem.

It runs for a specified number of iterations, and reads 2D coordinate data from a specified text file.

Currently memory leak-free! (Memcheck tested in Valgrind on UNIX)


**How it works**

1. The program (readfile.c) retrieves a simple list of 2D coordinate pairs (x y), which are read from the filename specified in main.c.

2. Knowing the number of coordinate pairs, the program (matrix.c) randomly generates an adjacency matrix representing a graph in which every node is visited once, and that is an appropriate size the number of nodes.

3. Next, the adjacency matrix is used to determine which nodes from the file data will be adjacent (distances.c) and the pythagorean distances between all the pairs of connecting nodes are calculated and summed.

4. The total graph distance is returned to the main optimization algorithm (simulated-annealing.c), and its scalar value is used as a state to be compared with many other states generated the same way.

5. The best state found so far is recorded, and if a new state has a lower distance, it replaces the best. If not, the optimizer stochastically determines whether to switch to the new state anyways.

6. Steps 2-5 are repeated for the number of iterations specified in main.c, and the best state found is returned.


**To do**

- Implement cryptographically secure random integer generation
- Optimize processing performance
- Explore visualization of graph configuration
