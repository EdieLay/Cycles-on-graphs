// Kruskal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip> 
#include <time.h>

using namespace std;

int const SIZE = 6;
int Graph[SIZE][SIZE];
int Col[SIZE];
int Ostov[SIZE - 1][2];

void fillgraph()
{
    int i, j;
    for (i = 1; i < SIZE; i++)
        for (j = 0; j < i; j++)
        {
            if (rand() % 2 == 1)
            {
                Graph[i][j] = rand() % 99 + 1;
                Graph[j][i] = Graph[i][j];
            }
            else
            {
                Graph[i][j] = 0;
                Graph[j][i] = 0;
            }
        }
}

void printgraph()
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            cout << setw(4) <<  Graph[i][j];
        cout << endl;
    }
}

bool ostov()
{
    int i, j, k, iMin, jMin, mindist, c;
    for (k = 0; k < SIZE - 1; k++)
    {
        mindist = 120;
        for (i = 1; i < SIZE; i++)
            for (j = 0; j < i; j++)
                if (Col[i] != Col[j] && Graph[i][j] < mindist && Graph[i][j] != 0)
                {
                    iMin = i;
                    jMin = j;
                    mindist = Graph[i][j];
                }
        Ostov[k][0] = iMin;
        Ostov[k][1] = jMin;
        c = Col[jMin];
        for (i = 0; i < SIZE; i++)
            if (Col[i] == c)
                Col[i] = Col[iMin];
    }
    for (i = 1; i < SIZE; i++)
        if (Col[i] != Col[i - 1])
            return false;
    return true;
}

void printostov()
{
    int i;
    for (i = 0; i < SIZE - 1; i++)
        cout << "(" << Ostov[i][0] + 1 << ", " << Ostov[i][1] + 1 << ")  ";
    cout << endl;
}

int main()
{
    srand(time(NULL));
    cout << setiosflags(ios::left);
    for (int i = 0; i < SIZE; i++)
        Col[i] = i;
    fillgraph();
    printgraph();
    if (ostov())
        printostov();
    else cout << "Graph is not connected" << endl;
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
