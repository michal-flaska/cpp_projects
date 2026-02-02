/*

// ORIGINAL CODE:

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

float cube[8][3] = {
    {-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},
    {-1,-1, 1},{1,-1, 1},{1,1, 1},{-1,1, 1}
};

int edges[12][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};

int main() {
    float a = 0;
    const int w = 80;
    const int h = 24;

    std::cout << "\033[2J\033[?25l";

    while (true) {
        char screen[h][w];
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                screen[y][x] = ' ';

        for (auto &e : edges) {
            for (int i = 0; i < 2; i++) {
                float x = cube[e[i]][0];
                float y = cube[e[i]][1];
                float z = cube[e[i]][2];

                float rx = x * cos(a) - z * sin(a);
                float rz = x * sin(a) + z * cos(a);

                int sx = (int)(rx * 10 + w / 2);
                int sy = (int)(y * 5 + h / 2);

                if (sx >= 0 && sx < w && sy >= 0 && sy < h)
                    screen[sy][sx] = '#';
            }
        }

        std::cout << "\033[H";
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++)
                std::cout << screen[y][x];
            std::cout << "\n";
        }

        a += 0.05f;
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}
*/

#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

// screen size
const int w = 80;
const int h = 30;

// basic vectors
struct Vec3 {
        float x, y, z;
};
struct Vec2 {
        int x, y;
};

// rotate point in 3d space
Vec3 rotate(Vec3 p, float ax, float ay, float az) {
        // rotate around x
        float y = p.y * cos(ax) - p.z * sin(ax);
        float z = p.y * sin(ax) + p.z * cos(ax);
        p.y = y;
        p.z = z;

        // rotate around y
        float x = p.x * cos(ay) + p.z * sin(ay);
        z = -p.x * sin(ay) + p.z * cos(ay);
        p.x = x;
        p.z = z;

        // rotate around z
        x = p.x * cos(az) - p.y * sin(az);
        y = p.x * sin(az) + p.y * cos(az);
        p.x = x;
        p.y = y;

        return p;
}

// project 3d point to 2d screen
Vec2 project(Vec3 p) {
        float d = 3.0f;               // camera distance
        float scale = d / (d + p.z);  // perspective
        return {(int)(p.x * scale * 15 + w / 2), (int)(p.y * scale * 8 + h / 2)};
}

// draw line using bresenham
void line(char screen[h][w], Vec2 a, Vec2 b) {
        int dx = abs(b.x - a.x);
        int dy = abs(b.y - a.y);
        int sx = a.x < b.x ? 1 : -1;
        int sy = a.y < b.y ? 1 : -1;
        int err = dx - dy;

        while (true) {
                // plot pixel if onscreen
                if (a.x >= 0 && a.x < w && a.y >= 0 && a.y < h)
                        screen[a.y][a.x] = '#';

                // reached end
                if (a.x == b.x && a.y == b.y)
                        break;

                int e2 = 2 * err;
                if (e2 > -dy) {
                        err -= dy;
                        a.x += sx;
                }
                if (e2 < dx) {
                        err += dx;
                        a.y += sy;
                }
        }
}

int main() {
        // cube vertices
        Vec3 cube[8] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};

        // cube edges
        int edges[12][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

        // rotation angles
        float ax = 0, ay = 0, az = 0;

        // clear screen + hide cursor
        std::cout << "\033[2J\033[?25l";

        while (true) {
                // clear frame buffer
                char screen[h][w];
                for (int y = 0; y < h; y++)
                        for (int x = 0; x < w; x++)
                                screen[y][x] = ' ';

                Vec2 pts[8];

                // rotate + project cube points
                for (int i = 0; i < 8; i++) {
                        Vec3 r = rotate(cube[i], ax, ay, az);
                        r.z += 4;  // push cube away from camera
                        pts[i] = project(r);
                }

                // draw edges
                for (auto& e : edges)
                        line(screen, pts[e[0]], pts[e[1]]);

                // draw frame
                std::cout << "\033[H";
                for (int y = 0; y < h; y++) {
                        for (int x = 0; x < w; x++)
                                std::cout << screen[y][x];
                        std::cout << "\n";
                }

                // animate
                ax += 0.03f;
                ay += 0.02f;
                az += 0.04f;

                std::this_thread::sleep_for(std::chrono::milliseconds(33));
        }
}
