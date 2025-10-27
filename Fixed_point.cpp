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


Or ,

    #include <iostream>
#include <cmath>
using namespace std;
double g(double x) {
    return pow(4 * x + 9, 1.0 / 3.0);
}
int main() {
    double x0, x1, tolerance;
    int maxIter;
    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;
    int iteration = 0;
    cout << "\nIteration\t x0\t\t g(x0)\n";
    cout << "----------------------------------------------------\n";
    do {
        x1 = g(x0);
        double error = fabs(x1 - x0);
        cout << iteration + 1 << "\t\t" << x0 << "\t\t" << x1 << endl;
        if (error < tolerance) {
            cout << "\nRoot found: " << x1 << endl;
            cout << "After " << iteration + 1 << " iterations.\n";
            return 0;
        }
        x0 = x1;
        iteration++;
    } while (iteration < maxIter);
    cout << "\nMethod did not converge after " << maxIter << " iterations." << endl;
    cout << "Last approximation: " << x1 << endl;

    return 0;
}
