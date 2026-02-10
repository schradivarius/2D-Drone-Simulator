#include "gridRender.h"

void renderGrid(double droneX, double droneY, double droneHeading) {
    const int gridSize = 40; // Size of the grid is (40x40)

    // This code will NOT actually render a graphical grid. Work in progress.
    for (int y = gridSize; y >= -gridSize; --y) {
        for (int x = -gridSize; x <= gridSize; ++x) {
            if (static_cast<int>(droneX) == x && static_cast<int>(droneY) == y) {
                // Render the drone with a character based on its heading
                if (droneHeading >= -M_PI / 4 && droneHeading < M_PI / 4) {
                    std::cout << '>'; // Facing right
                } else if (droneHeading >= M_PI / 4 && droneHeading < 3 * M_PI / 4) {
                    std::cout << '^'; // Facing up
                } else if (droneHeading >= -3 * M_PI / 4 && droneHeading < -M_PI / 4) {
                    std::cout << 'v'; // Facing down
                } else {
                    std::cout << '<'; // Facing left
                }
            } else {
                std::cout << '.'; // Empty space
            }
        }
        std::cout << std::endl;
    }
};

