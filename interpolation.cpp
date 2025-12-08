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
    cout << "Number of data : ";
    cin >> n;
    double x[n], y[n][n];
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << "Enter f(x) values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i][0];
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }
    cout << "\nForward Difference Table:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << y[i][j] << "\t";
        cout << endl;
    }

    // Input value to interpolate
    double xp;
    cout << "\nEnter value of x for interpolation: ";
    cin >> xp;

    // Newton Forward Interpolation
    double h = x[1] - x[0];
    double p = (xp - x[0]) / h;

    // Calculating interpolation value
    double yp = y[0][0];
    double term = 1;

    for (int i = 1; i < n; i++) {
        term *= (p - (i - 1));
        yp += (term * y[0][i]) / fact(i);
    }

    cout << "\nInterpolated value at x = " << xp << " is: " << yp << endl;

    return 0;
}
