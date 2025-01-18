#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
// Function to simulate the rocket trajectory and return the height reached
double simulate(double T, double ve, double Mpayload, double Mfuel) {
    double v = 0.0, h = 0.0; // Initialize velocity and height
    double M = Mpayload + Mfuel;

    // Constants
    const double rEarth = 6356.0;                // Earth's radius in km
    const double dt = 0.001;                     // Time step for numerical integration
    const double CD = 0.5;                      // Drag coefficient
    const double A = M_PI * pow(6.6e-3 / 2, 2); // Cross-sectional area

    // Perform simulation
    while (v > 0 || M > Mpayload) {
        double g = 3.962e5 / pow(h + rEarth, 2); // Gravity
        double rho = 1.225e6 * exp(-h / 9.0);    // Air density
        double drag = 0.5 * rho * CD * A * v * v;    // Drag force

        if (M > Mpayload) {
            v += dt * ((T / M) - g - (drag / M)); // Update velocity
            M -= (T * dt) / ve;                  // Update mass
        } else {
            v += dt * (-g - (drag / M));         // Update velocity
        }
        h += v * dt; // Update height

        // Check for escape velocity
        double vEscape = sqrt(2 * g * (h + rEarth));
        if (v > vEscape) return -1; // Return -1 if escape velocity is reached
    }
    return h; // Return final height
}

int main() {
    // Open the input file
    ifstream input("init_opt.txt");
    if (!input) {
        cout << "Error: Input file not found!";
        return 1;
    }

    // Read inputs from the file: thrust, exhaust velocity, payload mass
    double T, ve, Mpayload;
    input >> T >> ve >> Mpayload;

    // Calculate maximum possible fuel mass
    double g0 = 3.962e5 / pow(6356.0, 2); // Gravity at Earth's surface
    double MfuelMax = T / g0 - Mpayload;

    // Binary search for optimal fuel mass
    double low = 0.0, high = MfuelMax, bestFuel = -1;

    while (high - low > 0.002) { // Precision requirement of ±0.2%
        double mid = (low + high) / 2.0;
        double h = simulate(T, ve, Mpayload, mid);

        if (h == -1 || h > 2005.0) {
            high = mid; // Reduce fuel if height exceeds target
        } else if (h < 1995.0) {
            low = mid; // Increase fuel if height is below target
        } else {
            bestFuel = mid; // Found optimal fuel mass
            break;
        }
    }

    // Check if rocket is too heavy to reach target
    if (bestFuel == -1) {
        cout << "Rocket too heavy" ;
        return 1;
    }

    // Output optimal fuel mass 
    cout.precision(3); 
    cout << bestFuel;
    return 0;
}
