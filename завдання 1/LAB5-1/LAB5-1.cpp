#include "pch.h"
using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    int N = 0;

    Console::WriteLine(L"Вітаю!");

    //введення кількості двигунів
    while (true)
    {
        try
        {
            Console::Write(L"Введи кількість двигунів: ");
            N = Int32::Parse(Console::ReadLine());

            if (N <= 0)
            {
                Console::WriteLine(L"Кількість двигунів повинна бути більшою за 0!!!");
                continue;
            }
            break;
        }
        catch (FormatException^)//якщо користувач ввів не число
        {
            Console::WriteLine(L"Потрібно ввести ціле число!");
        }
        catch (OverflowException^) 
        {
            Console::WriteLine(L"введене число занадто велике або мале!");
        }
    }

    //створюємо масиви
    array<double>^ U = gcnew array<double>(N);
    array<double>^ I = gcnew array<double>(N);
    array<double>^ cosPhi = gcnew array<double>(N);
    array<double>^ P = gcnew array<double>(N);
    array<double>^ S = gcnew array<double>(N);

    Console::WriteLine(L"\n*** Каталог двигунів ***");
    Console::WriteLine(L"Введи дані для {0} двигунів:", N);

    //вводимо дані
    for (int i = 0; i < N; i++)
    {
        Console::WriteLine(L"\nДвигун N{0}:", i + 1);

        //напругa
        while (true)
        {
            try
            {
                Console::Write(L"Напруга живлення: U (В) = ");
                U[i] = Double::Parse(Console::ReadLine());
                if (U[i] <= 0) throw gcnew ArgumentOutOfRangeException();
                break;
            }
            catch (FormatException^)
            {
                Console::WriteLine(L"Введи число(наприклад: 220)!");
            }
            catch (ArgumentOutOfRangeException^)//якщо число є, але воно <= 0
            {
                Console::WriteLine(L"U повинно бути більше 0!");
            }
        }

        //струм
        while (true)
        {
            try
            {
                Console::Write(L"Струм,споживаний двигуном: I (А) = ");
                I[i] = Double::Parse(Console::ReadLine());
                if (I[i] <= 0) throw gcnew ArgumentOutOfRangeException();
                break;
            }
            catch (FormatException^)
            {
                Console::WriteLine(L"Введи число (наприклад: 5,3)!");
            }
            catch (ArgumentOutOfRangeException^)
            {
                Console::WriteLine(L"I повинно бути більше 0!");
            }
        }

        //cos φ
        while (true)
        {
            try
            {
                Console::Write(L"ККД (коефiцiєнт корисної дiї) двигуна: cos φ = ");
                cosPhi[i] = Double::Parse(Console::ReadLine());
                if (cosPhi[i] <= 0 || cosPhi[i] > 1)
                    throw gcnew ArgumentOutOfRangeException();
                break;
            }
            catch (FormatException^)
            {
                Console::WriteLine(L"Введи число(наприклад: 0,5)");
            }
            catch (ArgumentOutOfRangeException^)
            {
                Console::WriteLine(L"cos φ має бути в межах від 0 до 1");
            }
        }
    }

    //обчислюємо
    for (int i = 0; i < N; i++)
    {
        P[i] = Math::Sqrt(3) * U[i] * I[i] * cosPhi[i] / 1000.0;
        S[i] = Math::Sqrt(3) * U[i] * I[i] / 1000.0;
    }

    //виводимо результат
    Console::WriteLine(L"\nРезультати розрахунків:");
    Console::WriteLine(L"№\tU (В)\tI (А)\tcos φ\tP (кВт)\tS (кВа)");
    Console::WriteLine(L"───────────────────────────────────────────────");

    for (int i = 0; i < N; i++)
    {
        Console::WriteLine(L"{0}\t{1:F1}\t{2:F2}\t{3:F2}\t{4:F3}\t{5:F3}",
            i + 1, U[i], I[i], cosPhi[i], P[i], S[i]);
    }

    double sumP = 0, sumS = 0;
    for (int i = 0; i < N; i++)
    {
        sumP += P[i];
        sumS += S[i];
    }

    Console::WriteLine(L"\nЗагальна активна потужність: {0:F3} кВт", sumP);
    Console::WriteLine(L"Загальна повна потужність: {0:F3} кВа", sumS);
    Console::WriteLine(L"\nДо побачення!...");
    Console::ReadKey();

    return 0;
}
