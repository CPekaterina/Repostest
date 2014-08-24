#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

//change precision HERE!

typedef float dat;

//functions to declare:

dat p2 (dat x, int i, dat *y);                  // 2-point derivative
dat p3 (dat x, int i, dat *y);                  // 3-point derivative
void write(dat *z, dat *y, int x, char *file);  //function to write the results in a .dat file

int main()
{
    int stepnum;    //number of 10-steps to take
    dat *steps;     //dynamic array for the steplengths
    dat *deriv2p;   //dynamic array for the results of p2
    dat *deriv3p;   //dynamic array for the results of p3

    //Ask for number of steps!

    cout << "How many steps?" << endl;
    cin >> stepnum;

    //dynamic allocation of arrays

    steps = new dat[stepnum];
    deriv2p = new dat[stepnum];
    deriv3p = new dat[stepnum];

    //calculation of steplengths:

    for (int i=0; i<stepnum; i++)
    {
        steps[i]= 1./(pow(10,i));
    }

    //calculation of the derivatives at the different steplengths

    dat a = sqrt(2.);
    for (int i=0; i<stepnum; i++)
    {
        deriv2p[i]=p2(a,i, steps);

        deriv3p[i]=p3(a,i, steps);
    }

    //write the results of the derivatives into .dat files

    char file2[30]="res2p.dat";
    char file3[30]="res3p.dat";
    write(steps,deriv2p,stepnum,file2);
    write(steps,deriv3p,stepnum,file3);

    //compute the relative error

    dat *err2;
    err2 = new dat[stepnum];

    dat *err3;
    err3 = new dat[stepnum];

    dat cr = 1./3.;

    for (int i=0; i<stepnum; i++)
    {
        err2[i]=log10(abs((deriv2p[i]-cr)/cr));
        err3[i]=log10(abs((deriv3p[i]-cr)/cr));

    }

    //write the steplengths and their corresponding errors

    char errfile2[30]="err2p.dat";
    char errfile3[30]="err3p.dat";

    write(steps, err2, stepnum, errfile2);
    write(steps, err3, stepnum, errfile3);

return 0;
}

//functions' definitions

dat p2 (dat x, int i, dat *y)
{
    return (atan(x+y[i])-atan(x))/y[i];
}
dat p3 (dat x, int i, dat *y)
{
    return (atan(x+y[i])-atan(x-y[i]))/(2.*y[i]);
}

void write(dat*z, dat *y, int x, char *file)
{
    ofstream resout;
    resout.open(file);
    for (int i=0; i<x; i++)
    {
        cout << i << " " << y[i] << endl;
        resout << z[i] << " " << y[i] << endl;
    }
    resout.close();
}
