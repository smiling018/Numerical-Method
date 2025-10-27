// f(x) = x*x - 4*x -10

#include<iostream>
#include<cmath>
using namespace std;
double f( double x)
{
    return x*x - 4*x -10;
}
double f_prime( double x)
{
    return 2*x - 4;
}
int main()
{
    double a , b , tol;
    int maxiter;
    cout << "Enter initial guess: ";
    cin>> a;
    cout << "Enter tolerance : ";
    cin>> tol;
    cout << "Enter maximum number of iteration: ";
    cin>> maxiter;
    int i = 0;
    do
    {
        double fa = f(a);
        double fb = f_prime(a);
        if (fb == 0)
        {
            cout << "Error. Cannot continue\n";
            return 0;
        }
        b = a - (fa / fb );
        if (fabs( b - a) < tol)
        {
            cout << "\nRoot found: "<< b << "\nAfter " << i +1 << " iteration.\n";
            return 0;
        }
        a = b;
        i++;
    }while( i < maxiter);
    cout << "Method did not coverage.\nLast approximation : "<< b << endl;
    return 0;
}

