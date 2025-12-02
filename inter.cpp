#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n][n];

    // Input values
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter f(x) values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i][0];

    // Construct forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Print Forward Difference Table
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    // Interpolation input
    double xp;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> xp;

    // Compute h and p
    double h = x[1] - x[0];
    double p = (xp - x[0]) / h;

    // Newton forward interpolation
    double yp = y[0][0];
    double p_term = 1;

    for (int i = 1; i < n; i++) {
        p_term *= (p - (i - 1));
        yp += (p_term * y[0][i]) / tgamma(i + 1); // factorial using gamma: n! = tgamma(n+1)
    }

    cout << "\nInterpolated value at x = " << xp << " is " << yp << endl;

    return 0;
}
