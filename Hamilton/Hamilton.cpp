// Hamilton.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include<time.h>

using namespace std;

int const SIZE = 6;

int Graph[SIZE][SIZE];


vector<bool> visited;
vector<int> path;

bool hamilton(int curr)
{
    path.push_back(curr);
    if (path.size() == SIZE)
    {
        if (Graph[curr][0] == 1)
            return true;
        else
        {
            path.pop_back();
            return false;
        }
    }
    visited[curr] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (Graph[curr][i] == 1 && visited[i] != true)
            if (hamilton(i))
                return true;
    }
    visited[curr] = false;
    path.pop_back();
    return false;
}

void printgraph()
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            cout << Graph[i][j] << " ";
        cout << endl;
    }
}

void printpath()
{
    vector<int>::iterator iter = path.begin();
    cout << *(iter) + 1;
    iter++;
    while (iter != path.end())
    {
        cout << " -> " << *(iter) + 1;
        iter++;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int i, j;
    for (i = 0; i < SIZE; i++)
        visited.push_back(false);
    for (i = 1; i < SIZE; i++)
        for (j = 0; j < i; j++)
        {
            Graph[i][j] = rand() % 2;
            Graph[j][i] = Graph[i][j];
        }
    printgraph();
    if (hamilton(0))
        printpath();
    else cout << "No Hamilton cycle." << endl;
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
