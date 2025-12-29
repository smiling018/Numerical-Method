#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "Number of Item: ";
    cin >> n;
    double a[n][n], b[n], x[n] = {0} , tol;
    int maxIter;
    cout << "Enter coefficient matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter constant b:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Maximum iterations: ";
    cin >> maxIter;
    for (int iter = 1; iter <= maxIter; iter++) {
        double maxError = 0;
        for (int i = 0; i < n; i++) {
            double sum = b[i];

            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            double newX = sum / a[i][i];
            maxError = max(maxError, fabs(newX - x[i]));
            x[i] = newX;
        }
        if (maxError < tol) {
            cout << "\nConverged in " << iter << " iterations.\n";
            break;
        }
    }
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}

