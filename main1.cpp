#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x);
float f (float x);

int main()
{
    double h,x, toterr, minerr2, minerr3, minstep2, minstep3;
    x = sqrt(2);
    double result = 1./3.;
    minerr2=minerr3=result;


    for (h=0.1 ;h > 1e-20; h/=10.){

        double df2point = (f(x+h)-f(x))/h;
        double df3point = (f(x+h)-f(x-h))/(2*h);


        cout << "2-point derivative of atan(x) at sqrt(2) for steplength " << h << " is " << setprecision(10) << df2point << endl;
        toterr = abs(result-df2point);
        cout << "the total error is " << toterr << endl;

        if(toterr < minerr2) {minerr2=toterr; minstep2=h;}

        cout << "3-point derivative of atan(x) at sqrt(2) for steplength " << h << " is " << setprecision(10) << df3point << endl;
        toterr =abs(result-df3point);
        cout << "the total error is " << toterr << endl;

        if(toterr < minerr3) {minerr3=toterr; minstep3=h;}    }

    cout << "The smallest total error for the 2-point-derivative is " << minerr2 << endl;
    cout << "The corresponding steplength is " << minstep2 << endl;
    cout << "The smallest total error for the 3-point-derivative is " << minerr3 << endl;
    cout << "The corresponding steplength is " << minstep3 << endl;
    return 0;

}
double f (double x)
{
    return atan(x);
}
float f (float x)
{
    return atan(x);
}

