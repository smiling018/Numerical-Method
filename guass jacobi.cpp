#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Number of items: ";
    cin >> n;

    double a[n][n], b[n], x[n], old_x[n];
    double tolerance;
    int maxIter;

    // Initialize x to zero
    for (int i = 0; i < n; i++)
        x[i] = 0;

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter values of b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << "Enter tolerance: ";
    cin >> tolerance;

    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    for (int iter = 1; iter <= maxIter; iter++) {

        // Store previous values
        for (int i = 0; i < n; i++)
            old_x[i] = x[i];

        // Jacobi update
        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * old_x[j];  // 🔴 Key change
            }
            x[i] = sum / a[i][i];
        }

        // Compute error
        double error = 0;
        for (int i = 0; i < n; i++)
            error = max(error, fabs(x[i] - old_x[i]));

        if (error < tolerance) {
            cout << "\nConverged in " << iter << " iterations.\n";
            break;
        }
    }

    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;

    return 0;
}

