//Nojood Alnahdi
#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

// Function to check if a solution satisfies all constraints
bool isValid(int x, int y) {
    return (8 * x + 4 * y <= 48) &&         // Time constraint
           (2 * x + 5 * y <= 100) &&       // Soil constraint
           (2 * x + y <= 60) &&            // Water constraint
           (5 * x + 4 * y <= 200) &&       // Seeds constraint
           (x >= 1) &&                      // Minimum 1 lavender plant
           (y >= 1);                        // Minimum 1 rosemary plant
}

// Function to calculate the objective function
int calculateObjective(int x, int y) {
    return 20 * x + 30 * y;  // Profit function
}

// Function to find the initial best solution
void findInitialSolution(int& x, int& y, int& max_obj, const vector<int>& array_x, const vector<int>& array_y) {
    max_obj = 0;
    for (size_t i = 0; i < array_x.size(); ++i) {
        for (size_t j = 0; j < array_y.size(); ++j) {
            if (isValid(array_x[i], array_y[j])) {
                int obj = calculateObjective(array_x[i], array_y[j]);
                if (obj > max_obj) {
                    x = array_x[i];
                    y = array_y[j];
                    max_obj = obj;
                }
            }
        }
    }
}

// Function to perform a single local search iteration for better neighbors
bool performLocalSearch(int& x, int& y, int& max_obj) {
    bool improvement = false;
    // Try neighbors in all directions (step size = 1)
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;  // Skip the current position
            int new_x = x + dx;
            int new_y = y + dy;
            if (isValid(new_x, new_y)) {
                int new_obj = calculateObjective(new_x, new_y);
                if (new_obj > max_obj) {
                    x = new_x;
                    y = new_y;
                    max_obj = new_obj;
                    improvement = true;  // Found a better solution
                }
            }
        }
    }
    return improvement;
}

int main() {
    // Arrays for x and y values (removed 0 from both to enforce x >= 1 and y >= 1)
    vector<int> array_x = {1, 2, 3, 4, 5, 6, 7, 8};  
    vector<int> array_y = {1, 2, 3, 4, 5, 6, 7, 8};  

    // Variables for best solution
    int x = 0, y = 0, max_obj = 0;

    // Find initial solution
    findInitialSolution(x, y, max_obj, array_x, array_y);
    cout << "Initial Objective Function = $" << max_obj << endl;
    cout << "Initial Solution = (" << x << " lavender, " << y << " rosemary)" << endl << endl;

    // Perform local search for a fixed number of iterations (2 times)
    int fixed_iterations = 2; // we can change it as we want
    for (int i = 1; i <= fixed_iterations; ++i) {
        bool improved = performLocalSearch(x, y, max_obj);
        if (improved) {
            cout << "After Local Search Iteration " << i << ":" << endl;
            cout << "Objective Function = $" << max_obj << endl;
            cout << "Solution = (" << x << " lavender, " << y << " rosemary)" << endl << endl;
        } else {
            cout << "No improvement found in iteration " << i << "." << endl << endl;
        }
    }

    // Print final results
    cout << "Final Objective Function = $" << max_obj << endl;
    cout << "Final Solution = (" << x << " lavender, " << y << " rosemary)" << endl;

    return 0;
}
