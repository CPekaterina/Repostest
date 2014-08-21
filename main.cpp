#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double h,x;
    x = sqrt(2);
    
    double df2point = (f(x+h)-f(x))/h;
    double df3point = (f(x+h)-f(x-h))/(2*h);
    
    
    cin >> h;
    
    cout << "2-point derivative of 1/tan(x) at sqrt(2)" << df2point << endl;
    cout << "3-point derivative of 1/tan(x) at sqrt(2)" << df3point << endl;
    
    return 0;

}
double f (double x)
{
    return 1./tan(x);
}

