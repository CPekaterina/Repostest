#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

struct dat{float x;};

dat p2 (dat x, int i, dat *y);
dat p3 (dat x, int i, dat *y);
void write(dat *z, dat *y, int x, char *file);

//Don't forget the comments!

int main()
{
    int stepnum;
    dat *steps;
    dat *deriv2p;
    dat *deriv3p;



    cout << "How many steps?" << endl;
    cin >> stepnum;

    steps = new dat[stepnum];
    deriv2p = new dat[stepnum];
    deriv3p = new dat[stepnum];

    for (int i=0; i<stepnum; i++)
    {
        steps->x[i]= 1./(pow(10,i));
    }
    dat a = sqrt(2.);
    for (int i=0; i<stepnum; i++)
    {
        deriv2p->x[i]=p2(a,i, steps);

        deriv3p->x[i]=p3(a,i, steps);
    }
    char file2[30]="res2p.dat";
    char file3[30]="res3p.dat";
    write(steps,deriv2p,stepnum,file2);
    write(steps,deriv3p,stepnum,file3);

    // Compute the relative error

    dat *err2;
    err2 = new dat[stepnum];

    dat *err3;
    err3 = new dat[stepnum];


    for (int i=0; i<stepnum; i++)
    {
        err2->x[i]=log10(abs((deriv2p[i]-(1./3.))/(1./3.)));
        err3->x[i]=log10(abs((deriv3p[i]-(1./3.))/(1./3.)));

    }

    char errfile2[30]="err2p.dat";
    char errfile3[30]="err3p.dat";

    write(steps, err2, stepnum, errfile2);
    write(steps, err3, stepnum, errfile3);


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
dat p2 (dat x, int i, dat *y)
{
    return (atan(x+y->x[i])-atan(x))/y->x[i];
}
dat p3 (dat x, int i, dat *y)
{
    return (atan(x+y->x[i])-atan(x-y->x[i]))/(2.*y->x[i]);
}

void write(dat*z, dat *y, int x, char *file)
{
    ofstream resout;
    resout.open(file);
    for (int i=0; i<x; i++)
    {
        cout << i << " " << y->x[i] << endl;
        resout << z[i] << " " << y->x[i] << endl;
    }
    resout.close();
}
