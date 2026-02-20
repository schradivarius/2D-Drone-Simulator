#include "raylib.h"
#include <cmath>
#include <iostream>

struct DroneState {
    float x;
    float y;
    float z;
    float speed;
    float vx;
    float vy; 
    float vz;
};

int main() {
    InitWindow(800, 600, "Drone Simulator 3D");
    SetTargetFPS(60);

    DroneState drone{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

    Model droneModel = LoadModel("drone.obj"); // Load a 3D model for the drone

    // Camera setup
    Camera3D camera = {};
    camera.position = {0.0f, 5.0f, 10.0f};
    camera.target = {drone.x, drone.y, drone.z};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        // Update and draw will go here
        float thrust = 10.0f;
        float drag = 0.95f; // Drag force
        float dt = GetFrameTime();

        // Rotation logic, using WASD because gamer
        if (IsKeyDown(KEY_A)) {
            drone.vx -= thrust * dt;
        }
        if (IsKeyDown(KEY_D)) {
            drone.vx += thrust * dt;
        }
        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            drone.vy -= thrust * dt;
        }
         if (IsKeyDown(KEY_SPACE)) {
            drone.vy += thrust * dt;
        }
        if (IsKeyDown(KEY_S)) {
                drone.vz += thrust * dt;
        }
        if (IsKeyDown(KEY_W)) {
                drone.vz -= thrust * dt;
        }

        // Update position based on variables
        drone.vx *= drag; 
        drone.vy *= drag;
        drone.vz *= drag;
        drone.x += drone.vx * dt;
        drone.y += drone.vy * dt;
        drone.z += drone.vz * dt;

        if (drone.y < 0.0f) {
            drone.y = 0.0f;
            drone.vy = 0.0f; // Kill vertical velocity so it doesn't keep pushing down
        }

        // Update Camera to follow drone
        float camDistance = 10.0f;
        static float camAngleX = 0.0f;
        static float camAngleY = 0.0f;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseDelta = GetMouseDelta();
            camAngleX -= mouseDelta.x * 0.003f;
            camAngleY -= mouseDelta.y * 0.003f;
            if (camAngleY > 1.5f) camAngleY = 1.5f;
            if (camAngleY < -1.5f) camAngleY = -1.5f;
        }

        camera.position = {
            drone.x + camDistance * sinf(camAngleX) * cosf(camAngleY),
            drone.y + camDistance * sinf(camAngleY),
            drone.z + camDistance * cosf(camAngleX) * cosf(camAngleY)
        };
        camera.target = {drone.x, drone.y, drone.z};


        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawGrid(20, 1.0f); // Draw a grid for reference
                
                DrawModel(droneModel, {drone.x, drone.y, drone.z}, 1.0f, WHITE);

                EndMode3D();

        EndDrawing();
    }
    UnloadModel(droneModel);
    CloseWindow();
    return 0;
}