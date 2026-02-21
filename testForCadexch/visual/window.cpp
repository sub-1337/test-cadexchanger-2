#include <numbers>
#include "window.h"
#include "raylib.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

void drawCurve(const std::shared_ptr<Curve>& curve, Color color)
{
    const int segments = 50;
    const double maxT = 4.0 * std::numbers::pi;

    for (int i = 0; i < segments; ++i)
    {
        double t1 = maxT * i / segments;
        double t2 = maxT * (i + 1) / segments;

        auto p1 = curve->getPoint(t1);
        auto p2 = curve->getPoint(t2);

        DrawLine3D(
            { (float)p1[0], (float)p1[2], (float)p1[1] },
            { (float)p2[0], (float)p2[2], (float)p2[1] },
            color
        );
    }
}

void openVisualWindow(const std::vector<std::shared_ptr<Curve>>& curvesContainer, std::string log)
{

    SetTraceLogLevel(LOG_NONE);   // <<< отключаем вывод raylib

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "3D Curves Visualization");
    DisableCursor();
    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = { 15.0f, 15.0f, 15.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        for (const auto& curve : curvesContainer)
            drawCurve(curve, RED);

        EndMode3D();

        EndDrawing();
    }
    CloseWindow();
}