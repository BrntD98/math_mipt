#include <iostream>
#include <vector>

using namespace std;

vector<double> simple_iteration(vector<vector<double>> A, vector<double> b, double eps, int max_iter) {
    int n = A.size();
    vector<double> x(n, 0);
    vector<double> x_prev(n, 0);
    int iter = 0;
    double norm = 0;
    do {
        x_prev = x;
        for (int i = 0; i < n; i++) {
            double s = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    s += A[i][j] * x_prev[j];
                }
            }
            x[i] = (b[i] - s) / A[i][i];
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


