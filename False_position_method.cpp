#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {

    return x*x*x - 4*x - 9;
}
int main() {
    double a, b, c;
    int maxIter;
    double tol;
    cout<<"Enter a, b, tol, maxIter: ";
    cin>>a>>b>>tol>>maxIter;
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval." << endl;
        return 1;
    }
    cout << "\nIter\t a\t\t b\t\t c\t\t f(c)\n";
    for (int i = 1; i <= maxIter; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;
        if (fabs(f(c)) < tol) {
            cout << "\nRoot found at x = " << c << " after " << i << " iterations." << endl;
            return 0;
        }
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    cout << "\nMethod did not converge after " << maxIter << " iterations." << endl;
    return 0;
}
