#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_real.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>


#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

using namespace std;
const double r_stepsize = 1;
const int StringLength = 1000;
const double initPosition = 0.45;
const double k = 0.001;
const int TimeStep = 8192;
double y_Amp[StringLength + 1][TimeStep];

void initString()
{
	int x0 = StringLength * initPosition;
	for (int i = 1; i < StringLength; ++i)
	{
		y_Amp[i][0] = exp(-k * (i - x0) * (i - x0));
		y_Amp[i][1] = exp(-k * (i - x0) * (i - x0));
	}
}

void propagate(int Times)
{
	y_Amp[0][Times] = 0;
	y_Amp[StringLength][Times] = 0;
	for (int i = 1; i < StringLength; ++i)
	{
		y_Amp[i][Times] = 2 * (1 - r_stepsize*r_stepsize) * y_Amp[i][Times - 1] - y_Amp[i][Times - 2] + r_stepsize * r_stepsize * (y_Amp[i + 1][Times - 1] + y_Amp[i - 1][Times - 1]);
	}

}

int main()
{
	initString();
	double data[TimeStep];	
	for (int j = 2; j < TimeStep; ++j)
	{
		propagate(j);
		data[j] = y_Amp[50][j];
	}

	gsl_fft_real_radix2_transform(data, 1, 8192);
	double count,numIwant;	
	ofstream myfile;
	myfile.open ("FixedIdeal05.dat");
	for(int i = 0; i < TimeStep; i++)
	{
		count = i * 10 * 3;
		numIwant = sqrt((data[i] * data[i] + data[TimeStep - i - 1] * data[TimeStep - i - 1]) / 8192);
		myfile <<count<< "    " << numIwant <<endl;
	}

	myfile.close();
	return 0;
}
