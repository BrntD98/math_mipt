#include <iostream>
#include <vector>

using namespace std;

vector<double> gauss_seidel(vector<vector<double>> A, vector<double> b, double eps, int max_iter) {
    int n = A.size();
    vector<double> x(n, 0);
    vector<double> x_prev(n, 0);
    int iter = 0;
    double norm = 0;
    do {
        x_prev = x;
        for (int i = 0; i < n; i++) {
            double s1 = 0;
            for (int j = 0; j < i; j++) {
                s1 += A[i][j] * x[j];
            }
            double s2 = 0;
            for (int j = i + 1; j < n; j++) {
                s2 += A[i][j] * x_prev[j];
            }
            x[i] = (b[i] - s1 - s2) / A[i][i];
        }
        norm = 0;
        for (int i = 0; i < n; i++) {
            norm += pow(x[i] - x_prev[i], 2);
        }
        norm = sqrt(norm);
        iter++;
    } while (norm > eps && iter < max_iter);
    if (iter == max_iter) {
        cout << "Method failed to converge" << endl;
    }
    return x;
}
