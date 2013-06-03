#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

const double r_stepsize = 1;
const int StringLength = 100;
const double initPosition = 0.2;
const double k = 0.1;
const int TimeStep = 10;
double y_Amp[StringLength][TimeStep];

void initString()
{
	int x0 = StringLength * initPosition;
	for (int i = 1; i < StringLength - 1; ++i)
	{
		y_Amp[i][0] = exp(-k * (i - x0) * (i - x0));
		y_Amp[i][1] = exp(-k * (i - x0) * (i - x0));
	}
}

void propagate(int Times)
{
	y_Amp[0][Times] = 0;
	y_Amp[StringLength - 1][Times] = 0;
	for (int i = 1; i < StringLength - 1; ++i)
	{
		y_Amp[i][Times] = 2 * (1 - r_stepsize*r_stepsize) * y_Amp[i][Times - 1] - y_Amp[i][Times - 2] + r_stepsize * r_stepsize * (y_Amp[i + 1][Times - 1] + y_Amp[i - 1][Times - 1]);
	}

}

int main()
{
	initString();
	int TimeT = 50;
	for (int j = 2; j < TimeT; ++j)
	{
		propagate(j);
	}
	for (int i = 0; i < StringLength; ++i)
    {
        cout<<y_Amp[i][TimeT -1]<<"    "<<endl;
    }
    cout<<endl;
    return 0;

}
