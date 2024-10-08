# Search Algorithms Project - Maximizing Crop Productivity
for Optimization and Regression course
## Overview

This project implements search algorithms in C++ to **maximize the productivity** of a farmer's crops—specifically, lavender and rosemary. The aim is to determine the optimal quantity of each crop that can be grown within specified constraints, thereby increasing sales and profit.

## Problem Statement

A farmer aims to enhance the productivity of his lavender and rosemary crops to boost sales and profits within certain limitations:

- **Time Limit**: The total growth time must not exceed 48 weeks.
- **Water Usage**: The total water usage must not exceed 60 liters.
- **Soil Availability**: The total amount of soil used must not exceed 100 kg.

### Crop Requirements

- **Lavender**:
  - Time to ripen: 8 weeks
  - Water needed: 2 liters per plant
  - Soil needed: 2 kg per plant
  - Seeds needed: 4 grains
  - Sale price: $20

- **Rosemary**:
  - Time to ripen: 4 weeks
  - Water needed: 5 liters per plant
  - Soil needed: 5 kg per plant
  - Seeds needed: 3 grains
  - Sale price: $30

The objective is to find how many of each crop to plant to maximize profits.

## Objective Function

The objective function is defined as\( P \):


- \ Maximize  P = 20x + 30y


Where:
- \( x \) = number of lavender plants
- \( y \) = number of rosemary plants

### Constraints

The solution must satisfy the following constraints:

- \( 8x + 4y \leq 48 \) (Total weeks to ripen)
- \( 2x + y \leq 60 \) (Total liters of water)
- \( 2x + 5y \leq 100 \) (Total kg of soil)
- \( 5x + 4y \leq 200 \) (Total seeds)
- \( x \geq 1 \) (Ensures at least one lavender plant are grown)
- \( y \geq 1 \) (Ensures at least one rosemary plant are grown)

## Implementation

The program is implemented in C++ and uses a simple linear search approach to find the optimal solution. The code operates as follows:

1. **Initial Solution**: 
   - The program iterates through all possible combinations of lavender and rosemary plants to find an initial solution that maximizes profit while satisfying the constraints.

2. **Local Search**: 
   - The program then performs a local search for a fixed number of iterations (2 times) to improve upon the initial solution by exploring neighboring plant counts.


## Code Overview
For a detailed explanation and implementation, please refer to the uploaded source code files (.cpp).

## Conclusion
This project demonstrates the application of linear programming techniques to optimize crop yields within specified constraints, helping farmers make informed decisions to maximize their profits.





### Adjustability

The code can be easily adjusted to model more realistic scenarios. By modifying the `isValid` function, users can accommodate different growth patterns or varying profit margins. This function checks if a given combination of lavender and rosemary plants meets all the defined constraints. For instance, by changing the calculations inside the `isValid` function, you can redefine the relationships between plant growth times, water usage, soil requirements, and other factors.

Here's the `isValid` function for reference:

```cpp
bool isValid(int x, int y) {
    int max_time = max(8 * x, 4 * y);
    return (max_time <= 48) &&
           (5 * x + 4 * y <= 200) &&
           (2 * x + 5 * y <= 100) &&
           (2 * x + y <= 60) &&
           (x >= 1) &&
           (y >= 1);
}

