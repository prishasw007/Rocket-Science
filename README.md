# Rocket Science Simulation Project

# Introduction
### This project simulates rocket trajectories using numerical methods to calculate velocity, height, and fuel optimization under varying conditions. The project is divided into four tasks, each building on the previous to introduce new complexities such as gravity, air resistance, and fuel optimization.

# Input Files:
### init.txt: Used in Tasks 1, 2, and 3, containing 4 values (Thrust T, Exhaust velocity ve, Total mass Mtotal, and Payload mass Mpayload).
### init_opt.txt: Used in Task 4, containing 3 values (Thrust T, Exhaust velocity ve, Payload mass Mpayload).
### Output: Precision set to 3 significant figures using cout.precision(3).

# Tasks Overview
## Task 1: Maximum Velocity without Gravity or Air Resistance
### Simulates the rocket's motion ignoring gravity and air resistance to compute the maximum velocity.
### Output: Final speed (vfinal).
### Input: Read from init.txt.
### Filename: rocket_task1.cpp.

## Task 2: Maximum Height Considering Gravity
### Incorporates gravity to calculate the maximum height the rocket can reach.
### Output: Final height (hfinal). If escape velocity is reached, outputs: Escape velocity reached.
### Input: Read from init.txt.
### Filename: rocket_task2.cpp.

## Task 3: Maximum Height Considering Gravity and Air Resistance
### Adds air resistance into the model and computes the maximum height achievable.
### Output: Final height (hfinal). If escape velocity is reached, outputs: Escape velocity reached.
### Input: Read from init.txt.
### Filename: rocket_task3.cpp.

## Task 4: Optimal Fuel for a Target Height
### Calculates the optimal fuel mass required for the rocket to reach a height of 2000 km ± 5 km.
### Output: Optimal fuel mass (Mfuel). If the rocket cannot reach the target height, outputs: Rocket too heavy.
### Input: Read from init_opt.txt.
### Filename: rocket_task4.cpp

Output: Optimal fuel mass (Mfuel). If the rocket cannot reach the target height, outputs: Rocket too heavy.

Input: Read from init_opt.txt.
Filename: rocket_task4.cpp.

