#include <iostream>
#include <climits>

using std::cout;
/// Количество вершин графа
#define V 9

/// @brief Функция для поиска вершины с минимальным расстоянием, которая еще не включена в кратчайший путь
/// @param dist
/// @param sptSet
/// @return
int min_distance(int dist[], bool sptSet[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
/// @brief Функция для вывода кратчайших расстояний от источника до всех вершин
/// @param dist
void print_solution(int dist[])
{
    cout << "Pic \t Distance\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << "\n";
}

/// @brief Функция реализации алгоритма Дейкстры для матрицы смежности графа
/// @param
/// @param
void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // Массив для хранения кратчайших расстояний от источника
    bool sptSet[V]; // Массив для отметки вершин, включенных в кратчайший путь

    // Инициализация всех расстояний как бесконечность и отметка всех вершин как не включенных в кратчайший путь
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Расстояние от источника до самого себя всегда равно 0
    dist[src] = 0;

    // Находим кратчайшие расстояния для всех вершин графа
    for (int count = 0; count < V - 1; count++)
    {
        int u = min_distance(dist, sptSet); // Выбираем вершину с минимальным расстоянием из невключенных в кратчайший путь
        sptSet[u] = true;                   // Отмечаем вершину как включенную в кратчайший путь

        // Обновляем расстояния до смежных вершин
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Выводим кратчайшие расстояния
    print_solution(dist);
}

int main()
{
    // Пример матрицы смежности графа
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0); // Вызываем алгоритм Дейкстры для поиска кратчайших расстояний от вершины 0

    return 0;
}
