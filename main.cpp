#include <iostream>
#include <cmath>

struct DroneState {
    // Important to note that this functions on a 2D plane.
    double x; // X position
    double y; // Y position
    double heading; // Radians. 0 is facing right.
    double speed;
};

int main() {
    DroneState drone{0.0, 0.0, 0.0, 0.0}; // Initial state
    const double dt = 0.1; // seconds
}