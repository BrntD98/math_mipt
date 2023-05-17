#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 2) + 2 * x + 1; // функция, которую необходимо минимизировать
}

double df(double x) {
    return 2 * x + 2; // производная функции
}

double gradient_descent(double x0, double lr, int n_iterations) {
    double x = x0;
    for (int i = 0; i < n_iterations; i++) {
        double dx = -lr * df(x); // вычисляем изменение координаты
        x += dx; // обновляем координату
    }
    return x;
}

int main() {
    double x0 = -5; // начальное значение координаты
    double lr = 0.1; // скорость обучения
    int n_iterations = 100; // количество итераций

    double x_min = gradient_descent(x0, lr, n_iterations);

    cout << "Minimum point: " << x_min << endl;
    cout << "Minimum value: " << f(x_min) << endl;

    return 0;
}

