#include <iostream>
#include <cmath>
#include <stdlib.h>

# define M_PI           3.14159265358979323846  /* pi */



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

        // Command Processing
        switch (command) {
            case 'w': // Move forward
                drone.speed += 1.0; // Increase speed
                break;
            case 's': // Move backward
                drone.speed -= 1.0; // Decrease speed
                break;
            case 'a': // Turn left
                drone.heading += M_PI / 18; // Turn left by 10 degrees
                break;
            case 'd': // Turn right
                drone.heading -= M_PI / 18; // Turn right by 10 degrees
                break;
            default:
                std::cout << "Invalid Command: " << command << "Please enter a valid directional command. (w/a/s/d)" << std::endl;
        }

        // Update pos
        drone.x += drone.speed * std::cos(drone.heading * dt);
        drone.y += drone.speed * std::sin(drone.heading * dt);
        
        std::cout<< "x: " << drone.x << "| y: " << drone.y << "| heading: " << drone.heading << "| speed: " << drone.speed << std::endl;
    }

    return 0;
}