#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n][n];

    // Input x values
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    // Input y values
    cout << "Enter f(x) values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i][0];

    // Construct forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    // Print table
    cout << "\nForward Difference Table:\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
