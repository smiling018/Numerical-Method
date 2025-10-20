#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{
    return x*x*x - 4*x - 9;
}
int main()
{
    double a,b,tol;
    int maxIter;
    cout<<"Enter a, b, tol, maxIter: ";
    cin>>a>>b>>tol>>maxIter;
    if(f(a)*f(b)>=0)
    {
        cout<<"Invalid interval!\n";
        return 0;
    }
    int iter=0;
    double c;
    while(fabs(b-a) > tol && iter < maxIter)
    {
        iter++;
        c = (a+b)/2.0;
        if(f(c)==0.0)
           break;
        if(f(a)*f(c)<0)
            b=c;
        else
         a=c;
    }

    cout<<"Root = "<<(a+b)/2.0<<" after "<<iter<<" iterations\n";
    return 0;
}
