#include "gridRender.h"
#include <chrono>
#include <thread>
#include <cstdlib>

struct DroneState {
    // Important to note that this functions on a 2D plane!
    double x; // X pos
    double y; // Y pos
    double heading; // Direction the drone is heading in radians. 0 is facing right.
    double speed;
};

int main() {
    using clock = std::chrono::steady_clock;
    using seconds = std::chrono::duration<double>;

    // renderGrid(0.0, 0.0, 0.0); // Initial render of the grid with the drone at the center

    DroneState drone{0.0, 0.0, 0.0, 1.0}; // Initial state
    const double dt = 1/30.0;

    std::cout << "Simulator started." << std::endl;

    auto previousTime = clock::now(); // Tracks last frame time
    double accumulator = 0.0; // Stores "leftover" real time

    while(true) {
        auto currentTime = clock::now();
        seconds frameTime = currentTime - previousTime;
        previousTime = currentTime;

        accumulator += frameTime.count();

        while(accumulator >= dt) {
            // Update pos here
                drone.x += drone.speed * std::cos(drone.heading)* dt;
                drone.y += drone.speed * std::sin(drone.heading)* dt;

                #ifdef _WIN32
                    system("cls"); // Clear console on Windows
                #else
                    system("clear"); // Clear console on Unix/Linux
                #endif

                std::cout<< "X: " << drone.x << "\nY: " << drone.y << "\nHeading: " << drone.heading << "\nSpeed: " << drone.speed << std::endl;
            drone.x += drone.speed * std::cos(drone.heading)*dt;
            drone.y += drone.speed * std::sin(drone.heading)*dt;
            accumulator -= dt;
        }

        // Render grid
        // renderGrid(drone.x, drone.y, drone.heading); // Render the grid with the updated drone position and heading

        // Sleep to avoid CPU burn
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    /*
    while (false) {
        char command;

        std::cin >> command;

        if(!std::cin || command == 'q') {
            std::cout << "Simulator Stopped." << std::endl;
            break;
        }

        // Placeholder for command processing. In a real implementation, you would parse the command and update the drone's state accordingly.
        // For example, you could have commands like 'w' for forward, 's' for backward, 'a' for left turn, and 'd' for right turn.
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
                std::cout << "Unknown command: " << command << std::endl;
        }

        if(drone.speed < 0) {
            drone.speed = 0; // No negative speed values (this isn't velocity!)
        }

        if (drone.heading > M_PI) {
            drone.heading -= 2 * M_PI;
        } else if (drone.heading < -M_PI) {
            drone.heading += 2 * M_PI;
        }

        // Update pos
        drone.x += drone.speed * std::cos(drone.heading)* dt;
        drone.y += drone.speed * std::sin(drone.heading)* dt;
        
        renderGrid(drone.x, drone.y, drone.heading); // Render the grid with the updated drone position and heading

        std::cout<< "x: " << drone.x << "| y: " << drone.y << "| heading: " << drone.heading << "| speed: " << drone.speed << std::endl;
    }
    */
    return 0;
}
