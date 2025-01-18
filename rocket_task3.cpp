#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    // Open the input file
    ifstream input("init.txt");
    if (!input) {
        cout << "Error: Input file not found!" ;
        return 1;
    }

    // Read inputs from the file: thrust, exhaust velocity, total mass, payload mass
    double T, ve, Mtotal, Mpayload;
    input >> T >> ve >> Mtotal >> Mpayload;

    // Initialize variables
    double v = 0.0; // Velocity
    double h = 0.0; // Height
    double M = Mtotal;

    // Constants
    const double rEarth = 6356.0;  // Earth's radius in km
    const double dt = 0.001;       // Time step for numerical integration
    const double CD = 0.5;        // Drag coefficient
    const double A = M_PI * pow(6.6e-3 / 2, 2); // Cross-sectional area of the rocket

    // Perform simulation
    while (v > 0 || M > Mpayload) {
        double g = 3.962e5 / pow(h + rEarth, 2); // Gravity as a function of height
        double rho = 1.225e6 * exp(-h / 9.0);    // Air density as a function of height
        double drag = 0.5 * rho * CD * A * v * v;    // Drag force

        if (M > Mpayload) {
            v += dt * ((T / M) - g - (drag / M)); // Update velocity with thrust, gravity, and drag
            M -= (T * dt) / ve;                  // Update mass
        } else {
            v += dt * (-g - (drag / M));         // Update velocity with only gravity and drag
        }
        h += v * dt; // Update height

        // Check if velocity exceeds escape velocity
        double vEscape = sqrt(2 * g * (h + rEarth));
        if (v > vEscape) {
            cout << "Escape velocity reached" ;
            return 1;
        }
    }

    // Output the maximum height 
    cout.precision(3); 
    cout << h ;
    return 0;
}
