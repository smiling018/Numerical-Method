#include <iostream>#include <cmath>
using namespace std;
double g(double x) {
    return sqrt( 4*x +10 );
}
int main() {
    double x0, x1, tolerance;
    int maxIter;
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;
    int iter = 0;
    bool converged = false;
    cout << "\nIter\t x\n";
    while (iter < maxIter) {
        x1 = g(x0);
        cout << iter + 1 << "\t" << x1 << endl;
        if (fabs(x1 - x0) < tolerance) {
            converged = true;
            break;
        }
        x0 = x1;
        iter++;
    }
    if (converged) {
        cout << "\nFixed point found: " << x1 << " after " << iter + 1 << " iterations.\n";
    } else {
        cout << "\nMethod did not converge within " << maxIter << " iterations.\n";
    }
    return 0;
}
