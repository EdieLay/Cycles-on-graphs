// Euler.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> vershiny;
vector<int> cycle;

bool checkeuler(int** Graph, int ver, int size)
{
    int sum = 0, i;
    for (i = 0; i < size; i++)
        sum += Graph[ver][i];
    if (sum % 2 == 0 && ver == size - 1 && sum != 0)
        return true;
    else if (sum % 2 == 0 && sum != 0)
        return checkeuler(Graph, ver + 1, size);
    else return false;
}

bool checkmatrix(int** Graph, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < i + 1; j++)
            if (Graph[i][i] != 0 || Graph[i][j] != Graph[j][i])
                return false;
    return true;
}

void euler(int** Graph, int size)
{
    int i;
    while (!vershiny.empty())
    {
        i = 0;
        while (Graph[*(vershiny.end() - 1)][i] == 0 && i != size)
            i++;
        if (i == size)
        {
            cycle.push_back(*(vershiny.end() - 1));
            vershiny.pop_back();
        }
        else
        {
            Graph[*(vershiny.end() - 1)][i] = 0;
            Graph[i][*(vershiny.end() - 1)] = 0;
            vershiny.push_back(i);
        }
    }
    vector<int>::iterator icycle = cycle.begin();
    while (icycle != cycle.end())
    {
        cout << *(icycle) + 1 << " ";
        icycle++;
    }
    cout << endl;
}

void printgraph(int** Graph, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            cout << Graph[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int size, i, j;
    cout << "Enter number of nodes: ";
    cin >> size;
    int** Graph = new int*[size];
    for (i = 0; i < size; i++)
        Graph[i] = new int[size];
    /*for (i = 1; i < size; i++)
        for (j = 0; j < i; j++)
        {
            Graph[i][j] = rand() % 2;
            Graph[j][i] = Graph[i][j];
        }
    for (i = 0; i < size; i++)
        Graph[i][i] = 0;
    printgraph(Graph, size);*/
    cout << "Enter the graph:" << endl;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            cin >> Graph[i][j];
    vershiny.push_back(0);
    if (checkeuler(Graph, 0, size) && checkmatrix(Graph, size))
        euler(Graph, size);
    else cout << "Error! Graph is not matching conditions of existing Euler's cycle." << endl;
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
