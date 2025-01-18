#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    // Open the input file
    ifstream input("init.txt");
    if (!input) {
        cout << "Error: Input file not found!" << endl;
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
    const double rEarth = 6356.0; // Earth's radius in km
    const double dt = 0.001;      // Time step for numerical integration
    // Perform simulation
    while (v > 0 || M > Mpayload) {
        double g = 3.962e5 / pow(h + rEarth, 2); // Gravity as a function of height
        if (M > Mpayload) {
            v += dt * ((T / M) - g); // Update velocity with thrust and gravity
            M -= (T * dt) / ve;      // Update mass
        } else {
            v += dt * (-g);          // Update velocity with only gravity
        }
        h += v * dt; // Update height
        // Check if velocity exceeds escape velocity
        double vEscape = sqrt(2 * g * (h + rEarth));
        if (v > vEscape) {
            cout << "Escape velocity reached";
            return 1;
        }
    }
    // Output the maximum height 
    cout.precision(3) 
    cout << h;
    return 0;
}