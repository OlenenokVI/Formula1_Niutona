#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath> 

// задание 2.2
/*
для создания независимого такого же массива я использовала этот цикл:
for (int i = 0; i < n; i++) {
    div_diff[i] = Y[i];
}
который поэлементно добавлял значения в новый массив.
*/


void calculate_coeffs(double X[], double Y[], int n, double a[]) {
    double div_diff[100];

    for (int i = 0; i < n; i++) {
        div_diff[i] = Y[i];
    }

    a[0] = div_diff[0]; 
    if (std::abs(a[0]) < 0.0000001)
    {
        std::cout << "a0: " << 0 << std::endl;
    }
    else {
        std::cout << "a0: " << std::fixed << std::setprecision(6) << a[0] << std::endl;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            div_diff[i] = (div_diff[i + 1] - div_diff[i]) / (X[i + k] - X[i]);
        }

        a[k] = div_diff[0];
        if (std::abs(a[k]) < 0.0000001)
        {
            std::cout << "a" << k << ": " << 0 << std::endl;
        }
        else {
            std::cout << "a" << k << ": " << std::fixed << std::setprecision(6) << a[k] << std::endl;
        }

    }
}

double interpolate(double X[], double Y[], int n, double x_to_find) {
    double a[100]; // Массив для коэффициентов
    calculate_coeffs(X, Y, n, a);

    double result = 0.0;
    double multiplier = 1.0;

    for (int i = 0; i < n; i++) {
        result += a[i] * multiplier;
        multiplier *= (x_to_find - X[i]);
    }

    return result;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double X[] = { 1, 3, 6, 8, 19, 21, 32, 33, 40, 45 };
    double Y[] = { 0, -5, 10, 16, 18, 19, -4, -10, -15, 0 };
    int n = 10; // Количество точек

    //точка x = 2
    double x = 2.0;

    std::cout << "\t----- Вычисление коэффициентов -----" << std::endl;
    double result = interpolate(X, Y, n, x);

    std::cout << "\n-----------------------" << "\n\n";
    std::cout << "Итоговый результат для x = " << 2 << ": " << std::fixed << std::setprecision(6) << result << "\n\n";

    return 0;
}