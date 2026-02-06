#include <iostream>
#include <cmath>
#include <stdlib.h>

struct DroneState {
    // Important to note that this functions on a 2D plane!
    double x; // X pos
    double y; // Y pos
    double heading; // Direction the drone is heading in radians. 0 is facing right.
    double speed;
};

int main() {
    DroneState drone{0.0, 0.0, 0.0, 0.0}; // Initial state
    const double dt = 0.1; // in seconds

    std::cout << "Simulator started." << std::endl;

    while (true) {
        char command;

        std::cin >> command;

        if(!std::cin || command == 'q') {
            std::cout << "Simulator Stopped." << std::endl;
            break;
        }

        // Placeholder for command processing. In a real implementation, you would parse the command and update the drone's state accordingly.
        // For example, you could have commands like 'w' for forward, 's' for backward, 'a' for left turn, and 'd' for right turn.

        // Update pos
        drone.x += drone.speed * std::cos(drone.heading * dt);
        drone.y += drone.speed * std::sin(drone.heading * dt);
        
        std::cout<< "x: " << drone.x << "y: " << drone.y << "heading: " << drone.heading << "speed: " << drone.speed << std::endl;
    }

    return 0;
}