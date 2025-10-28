#include "pch.h"
using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    int N = 0, M = 0;
    Console::Write(L"Вітаю!");
    //виводимо кількість рядків
    while (true)
    {
        try
        {
            Console::Write(L"\nВведи кількість рядків N: ");
            N = Int32::Parse(Console::ReadLine());

            if (N <= 0)
            {
                Console::WriteLine(L"Кількість рядків повинна бути більшою за 0!!!");
                continue;
            }
            break;
        }
        catch (FormatException^)
        {
            Console::WriteLine(L"Введи ціле число!");
        }
        catch (OverflowException^)
        {
            Console::WriteLine(L"Значення занадто велике або мале!");
        }
    }

    //виводимо кількістб стовпців
    while (true)
    {
        try
        {
            Console::Write(L"Введи кількість стовпців M: ");
            M = Int32::Parse(Console::ReadLine());

            if (M <= 0)
            {
                Console::WriteLine(L"Кількість стовпців повинна бути більшою за 0!!!");
                continue;
            }
            break;
        }
        catch (FormatException^)
        {
            Console::WriteLine(L"Введи ціле число!");
        }
        catch (OverflowException^)
        {
            Console::WriteLine(L"Значення занадто велике або мале!");
        }
    }

    //створюємо двовимірний масив
    array<int, 2>^ matrix = gcnew array<int, 2>(N, M);

    //виводимо елементи матриці
    Console::WriteLine(L"\nВведи елементи матриці:");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            while (true)
            {
                try
                {
                    Console::Write(L"matrix[{0},{1}] = ", i, j);
                    matrix[i, j] = Int32::Parse(Console::ReadLine());
                    break;
                }
                catch (FormatException^)
                {
                    Console::WriteLine(L"Введи ціле число!");
                }
                catch (OverflowException^)
                {
                    Console::WriteLine(L"Значення занадто велике або мале!");
                }
            }
        }
    }

    //виводимо початкову матрицю
    Console::WriteLine(L"\nПочаткова матриця:");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Console::Write(L"{0}\t", matrix[i, j]);
        }
        Console::WriteLine();
    }

    //сортування кожного стовпця за зменшенням
    for (int col = 0; col < M; col++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - i - 1; j++)
            {
                if (matrix[j, col] < matrix[j + 1, col])
                {
                    int temp = matrix[j, col];
                    matrix[j, col] = matrix[j + 1, col];
                    matrix[j + 1, col] = temp;
                }
            }
        }
    }

    //виводимо відсортовану матрицю
    Console::WriteLine(L"\nСтовпці відсортовані за зменшенням:");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Console::Write(L"{0}\t", matrix[i, j]);
        }
        Console::WriteLine();
    }

    Console::WriteLine(L"\nВиходимо...");
    Console::ReadKey();

    return 0;
}
