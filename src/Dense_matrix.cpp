#include <cmath>
#include <vector>
#include <gtest/gtest.h>

class DenseMatrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    DenseMatrix(int r, int c) : rows(r), cols(c), data(r, std::vector<double>(c)) {}

    double& operator()(int i, int j) {
        return data[i][j];
    }

    const double& operator()(int i, int j) const {
        return data[i][j];
    }

    int nrows() const {
        return rows;
    }

    int ncols() const {
        return cols;
    }

    // Метод Хаусхолдера для преобразования матрицы в верхнетреугольную форму
    void householder() {
        for (int k = 0; k < cols - 1; k++) {
            std::vector<double> v(rows - k);
            double beta = 0.0;

            for (int i = k; i < rows; i++) {
                v[i - k] = data[i][k];
                beta += v[i - k] * v[i - k];
            }

            beta = sqrt(beta);

            if (v[k] > 0) {
                beta = -beta;
            }

            v[k] -= beta;

            double alpha = 0.0;

            for (int i = k; i < rows; i++) {
                alpha += v[i - k] * data[i][k];
            }

            alpha /= beta * (beta - v[k]);

            for (int j = k; j < cols; j++) {
                double s = 0.0;

                for (int i = k; i < rows; i++) {
                    s += v[i - k] * data[i][j];
                }

                s /= beta * (beta - v[k]);

                for (int i = k; i < rows; i++) {
                    data[i][j] -= s * v[i - k];
                }
            }

            for (int i = k + 1; i < rows; i++) {
                data[i][k] = v[i - k];
            }
        }
    }
};

