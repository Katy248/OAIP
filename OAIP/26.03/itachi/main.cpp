#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <vector>
#define GRAPH_SIZE 6

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::fill;

int *algorithm(int graph[6][6])
{
    static int path[GRAPH_SIZE];
    fill(begin(path), end(path), 0);
    path[0] = 0;
    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        for (int j = 0; j < GRAPH_SIZE; j++)
        {
            if (graph[i][j] == 0)
                continue;

            if (path[j] == 0)
            {
                path[j] = graph[i][j] + path[i];
                continue;
            }
            else if (path[i] + graph[i][j] < path[j])
                path[j] = graph[i][j] + path[i];
        }
    }
    path[0] = 0;
    return path;
}

int main()
{
    int graph[GRAPH_SIZE][GRAPH_SIZE] =
        {{0, 7, 9, 0, 0, 14},
         {7, 0, 10, 15, 0, 0},
         {9, 10, 0, 11, 0, 2},
         {0, 15, 11, 0, 6, 0},
         {0, 0, 0, 6, 0, 9},
         {14, 0, 2, 0, 9, 0}};

    int *a = algorithm(graph);
    cout << "Матрица смежности графа:" << endl;
    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        for (int j = 0; j < GRAPH_SIZE; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < GRAPH_SIZE; i++)
        cout << "Минимальный путь от 1 к " << i + 1 << " - " << a[i] << endl;

    cout << endl;
    return 0;
}
