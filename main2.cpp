#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

float p2 (float x, int i, float *y);
float p3 (float x, int i, float *y);
void write(float *y, int x);

int main()
{
    int stepnum;
    float *steps;
    float *deriv2p;
    float *deriv3p;



    cout << "How many steps?" << endl;
    cin >> stepnum;

    steps = new float[stepnum];
    deriv2p = new float[stepnum];
    deriv3p = new float[stepnum];

    for (int i=0; i<stepnum; i++)
    {
        steps[i]=1./(pow(10,i));
    }

    for (int i=0; i<stepnum; i++)
    {
        deriv2p[i]=p2(sqrt(2),i, steps);

        deriv3p[i]=p3(sqrt(2),i, steps);
    }

    write(deriv2p,stepnum);
    write(deriv3p,stepnum);

    // Compute the relative error

    float *err2;
    err2 = new float[stepnum];

    float *err3;
    err3 = new float[stepnum];


    for (int i=0; i<stepnum; i++)
    {
        err2[i]=log10(abs((deriv2p[i]-1./3.)/(1./3.)));
        err3[i]=log10(abs((deriv3p[i]-1./3.)/(1./3.)));

    }


/*  double h,x, toterr, minerr2, minerr3, minstep2, minstep3;
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
*/

return 0;
}
float p2 (float x, int i, float *y)
{
    return (atan(x+y[i])-atan(x))/y[i];
}
float p3 (float x, int i, float *y)
{
    return (atan(x+y[i])-atan(x-y[i]))/(2.*y[i]);
}

void write(float *y, int x)
{
    ofstream resout;
    resout.open("res2p.txt");
    for (int i=0; i<x; i++)
    {
        cout << i << " " << y[i] << endl;
        resout << y[i] << endl;
    }
    cout << "Success?" << endl;
    resout.close();
}
