#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Open the input file
    ifstream input("init.txt");
    if (!input) {
        cout << "Error: Input file not found!";
        return 1;
    }

    // Read inputs from the file: thrust, exhaust velocity, total mass, payload mass
    double T, ve, Mtotal, Mpayload;
    input >> T >> ve >> Mtotal >> Mpayload;

    // Initialize velocity and mass
    double v = 0.0;
    double M = Mtotal;

    // Time step for numerical integration
    const double dt = 0.001;

    // Perform simulation until all fuel is consumed
    while (M > Mpayload) {
        v += (T / M) * dt;             // Update velocity
        M -= (T * dt) / ve;            // Update mass
    }

    // Output the final velocity 
    cout.precision(3) ;
    cout << v;
    return 0;
}
