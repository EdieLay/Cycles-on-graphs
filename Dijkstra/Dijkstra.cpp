// Dijkstra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip> 
#include <time.h>
#include <vector>

using namespace std;

int const SIZE = 6, INF = 999, START = 0, FINISH = SIZE - 1;
int Graph[SIZE][SIZE];
bool Active[SIZE];
int R[SIZE], P[SIZE];

void fillgraph()
{
    int i, j;
    Graph[0][0] = INF;
    for (i = 1; i < SIZE; i++)
        for (j = 0; j < i; j++)
        {
            Graph[i][i] = INF;
            if (rand() % 2 == 1)
            {
                Graph[i][j] = rand() % 99 + 1;
                Graph[j][i] = Graph[i][j];
            }
            else
            {
                Graph[i][j] = INF;
                Graph[j][i] = INF;
            }
        }
}

void printgraph()
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            if (Graph[i][j] != INF)
                cout << setw(4) << Graph[i][j];
            else cout << setw(4) << "-";
        cout << endl;
    }
}

void dijkstra()
{
    int i, j, mindist, kmin;
    for (i = 0; i < SIZE - 1; i++)
    {
        mindist = 150;
        for (j = 0; j < SIZE; j++)
            if (Active[j] && R[j] < mindist)
            {
                mindist = R[j];
                kmin = j;
            }
        Active[kmin] = false;
        for (j = 0; j < SIZE; j++)
            if (R[kmin] + Graph[kmin][j] < R[j] && j != START)
            {
                R[j] = R[kmin] + Graph[kmin][j];
                P[j] = kmin;
            }
    }
}

void printpath()
{
    int i = FINISH;
    cout << "Shortest path from node " << START + 1 << " to the node " << FINISH + 1 << endl;
    vector<int> path;
    while (i != -1)
    {
        path.push_back(i);
        i = P[i];
    }
    vector<int>::iterator iter = path.end();
    while (iter != path.begin())
    {
        cout << *(iter - 1) + 1 << " ";
        iter--;
    }
    cout << endl;
    cout << "Length of this path: " << R[FINISH] << endl;
}

int main()
{
    srand(time(NULL));
    cout << setiosflags(ios::left);
    fillgraph();
    printgraph();
    for (int i = 0; i < SIZE; i++)
    {
        Active[i] = true;
        R[i] = Graph[START][i];
        P[i] = START;
    }
    int check;
    for (int i = 0; i < SIZE; i++)
    {
        check = 0;
        for (int j = 0; j < SIZE; j++)
            if (Graph[i][j] != INF)
            {
                check = 1;
                break;
            }
        if (check == 0)
        {
            cout << "Graph is not connected" << endl;
            return 0;
        }
    }
    Active[START] = false;
    P[START] = -1;
    dijkstra();
    if (R[FINISH] < INF)
        printpath();
    else cout << "There is no path from node " << START + 1 << " to the node " << FINISH + 1 << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
