/*
    A demonstration of the flood fill algorithm. 
    Slowly explores nodes in 4 directions in a FIFO priority and fills them.
    Made by Alphexus during a class period because I was bored.
*/

#include <iostream>
#include <queue>
#include <chrono>
#include <thread>

const int COLLUMNS = 20, ROWS = 10;
const int Y_START = 5, X_START = 7;

int grid[ROWS][COLLUMNS] = {
    {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0},
};

typedef std::pair<int, int> nodeTemplate;

void initialize();
void render();
void floodfill();

int main() {
    grid[Y_START][X_START] = 0;
    render();
    floodfill();
}

void render() {
    std::cout << "\033[2J\033[0;0H"; // clear terminal
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLLUMNS; x++) {
            std::cout << ((grid[y][x] == 1) ? "▉" : " ");
        }
        std::cout << "\n";
    }
}

void floodfill() {
    std::queue<nodeTemplate> frontier;
    frontier.push(std::make_pair(Y_START, X_START));

    while (!frontier.empty()) {
        nodeTemplate n = frontier.front();
        frontier.pop();
        if (grid[n.first][n.second] != 1) {
            grid[n.first][n.second] = 1;
            frontier.push(std::make_pair(n.first, n.second-1)); // West 
            frontier.push(std::make_pair(n.first, n.second+1)); // East
            frontier.push(std::make_pair(n.first-1, n.second)); // North 
            frontier.push(std::make_pair(n.first+1, n.second)); // South
            render();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
