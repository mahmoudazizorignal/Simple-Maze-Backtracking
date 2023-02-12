
/*
 * Assignment 3 - OOP - problem 3 in sheet 3 
 *  
 * This code is written by Mahmoud Mamdouh a student at Faculty of Computer Science - Cairo University
 * 		copyright © Mahmoud Mamdouh Abdelaziz
 */




#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define N 9
int solution[N][N] = {};

void DisplayBoard();
bool isSafe(int r, int c, int maze[N][N]);
bool FindSolution(int maze[N][N], int r = 0, int c = 0);
void PrintSolution(int maze[N][N]);

int main()
{
    int maze[N][N] = {
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 1}
    };

    PrintSolution(maze);
	return 0;
}





void DisplayBoard()
{
    cout << "==================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cout << solution[i][j] << " ";
        cout << endl;
    }
    cout << "==================\n";
}
bool isSafe(int r, int c, int maze[N][N])
{
    if (r >= 0 && c >= 0 && r < N && c < N && maze[r][c] == 1) 
        return true;

    return false;
}
bool FindSolution(int maze[N][N], int r = 0, int c = 0) 
{
    if (r == N - 1 && c == N - 1)
    {
        solution[r][c] = 1;
        return true;
    }

    if (isSafe(r, c, maze)) 
    {
        solution[r][c] = 1;
        if (FindSolution(maze, r + 1, c))
            return true;

        if (FindSolution(maze, r, c + 1))
            return true;
        solution[r][c] = 0;
    }

    return false;
}
void PrintSolution(int maze[N][N]) 
{
    if (FindSolution(maze))
    {
        DisplayBoard();
    }
    else {
        cout << "No Solution Exists\n";
    }

}
