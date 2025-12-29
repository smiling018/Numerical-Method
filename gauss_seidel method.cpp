#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    double a[10][10], b[10], x[10] = {0}, old_x[10];
    int maxIter;
    double tolerance;

    cout << "Enter coefficients of matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter constants vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << "Enter tolerance: ";
    cin >> tolerance;

    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    for (int iter = 1; iter <= maxIter; iter++) {
        for (int i = 0; i < n; i++)
            old_x[i] = x[i];

        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x[i] = sum / a[i][i];
        }

        // Check convergence
        double error = 0;
        for (int i = 0; i < n; i++)
            error = max(error, fabs(x[i] - old_x[i]));

        if (error < tolerance) {
            cout << "\nConverged in " << iter << " iterations.\n";
            break;
        }
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;

    return 0;
}
