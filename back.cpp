#include <iostream>
using namespace std;

int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}
int main() {
    int n;
    cout << "Number of data: ";
    cin >> n;

    double x[n], y[n][n];

    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter f(x) values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i][0];
    // Backward Difference Table
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
    cout << "\nBackward Difference Table:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j <= i; j++)
            cout << y[i][j] << "\t";
        cout << endl;
    }

    // Value to interpolate
    double xp;
    cout << "\nEnter value of x for interpolation: ";
    cin >> xp;

    double h = x[1] - x[0];
    double p = (xp - x[n - 1]) / h;

    // Newton Backward Interpolation Formula
    double yp = y[n - 1][0];
    double term = 1;

    for (int i = 1; i < n; i++) {
        term *= (p + (i - 1));
        yp += (term * y[n - 1][i]) / fact(i);
    }

    cout << "\nInterpolated value at x = " << xp << " is: " << yp << endl;

    return 0;
}
