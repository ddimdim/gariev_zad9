// prakt9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <Windows.h>


DWORD WINAPI QuadraticEquation(LPVOID data)
{
    double* abc = (double*)data;
    double a = abc[0];
    double b = abc[1];
    double c = abc[2];
    double disc = b * b - 4 * a * c;
    if (disc < 0)
    {
        std::cout << "Уравнение не имеет корней\n";
    }
    else if (disc == 0)
    {
        double x = -b / 2 * a;
        std::cout << "Есть только один корень: " << x << "\n";
    }
    else
    {
        double x1 = (-b + sqrt(disc)) / (2 * a);
        double x2 = (-b - sqrt(disc)) / (2 * a);
        std::cout << "Первый корень: " << x2 << "\nВторой корень: " << x1 << "\n";
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double data1[3] = { 4, 4, 1 };
    double data2[3] = { 1, -5, 6 };
    std::cout << "Первые данные: " << data1[0] << "; " << data1[1] << "; " << data1[2] << "; \n";
    std::cout << "Вторые данные: " << data2[0] << "; " << data2[1] << "; " << data2[2] << "; \n";
    HANDLE hThreads[2];
    DWORD IDThread;
    hThreads[0] = CreateThread(NULL, 0, QuadraticEquation, data1, 0, &IDThread);
    hThreads[1] = CreateThread(NULL, 0, QuadraticEquation, data2, 0, &IDThread);
    if (hThreads[0] == NULL)
        return GetLastError();
    if (hThreads[1] == NULL)
        return GetLastError();
    WaitForMultipleObjects(2, hThreads,TRUE, INFINITE);
    CloseHandle(hThreads[0]);
    CloseHandle(hThreads[1]);


    
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
