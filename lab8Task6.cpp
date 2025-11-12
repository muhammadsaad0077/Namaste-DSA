#include<iostream>
using namespace std;

#define N 5   

void printSolution(int sol[N][N]) {
    cout << "\nSolution Path (1 = path taken, 0 = not visited):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y) {

    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}

// Recursive backtracking function
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: if destination (4,4) is reached
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;  // mark the destination
        return true;
    }

    // Check if current cell is valid for movement
    if (isSafe(maze, x, y) == true) {
        // Mark current cell as part of the solution path
        sol[x][y] = 1;

        // Move Down (x+1, y)
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Move Right (x, y+1)
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // If moving Down and Right doesn’t work → Backtrack
        sol[x][y] = 0;  // unmark this cell
        return false;
    }

    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};  

    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        cout << "No path found! The lion cannot reach the meat.\n";
        return false;
    }

    printSolution(sol);
    return true;
}

int main() {
    // Maze representation (1 = open path, 0 = obstacle)
    int maze[N][N] = {
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    
    cout << "Initial Maze (1 = path, 0 = obstacle):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    solveMaze(maze);

    return 0;
}
