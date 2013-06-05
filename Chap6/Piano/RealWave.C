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

const double r_square = 0.25 * 0.25;
const int StringLength = 9;
const double initPosition = 0.2;
const double k = 0.001;
const int TimeStep = 3920;
const double bxDelta_T2 = 1 / 152000;
const double epsilon = 8.7 * pow(10,-4);
const double Msquare = StringLength * StringLength;
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
	y_Amp[1][Times] = 2 * (1 - r_square - 3 * epsilon * r_square * Msquare - bxDelta_T2/2) * y_Amp[1][Times - 1] - (1 - bxDelta_T2) * y_Amp[1][Times - 2] + r_square * (1 + 4 * epsilon * Msquare) * y_Amp[2][Times - 1] - epsilon * r_square * Msquare * (y_Amp[3][Times - 1] - y_Amp[1][Times - 1]);
	for (int i = 2; i < StringLength - 1; ++i)
	{
		y_Amp[i][Times] = 2 * (1 - r_square - 3 * epsilon * r_square * Msquare - bxDelta_T2/2) * y_Amp[i][Times - 1] - (1 - bxDelta_T2) * y_Amp[i][Times - 2] + r_square * (1 + 4 * epsilon * Msquare) * (y_Amp[i + 1][Times - 1] + y_Amp[i - 1][Times - 1]) - epsilon * r_square * Msquare * (y_Amp[i + 2][Times - 1] + y_Amp[i - 2][Times - 1]);
	}
	y_Amp[StringLength - 1][Times] = 2 * (1 - r_square - 3 * epsilon * r_square * Msquare - bxDelta_T2/2) * y_Amp[StringLength - 1][Times - 1] - (1 - bxDelta_T2) * y_Amp[StringLength - 1][Times - 2] + r_square * (1 + 4 * epsilon * Msquare) * y_Amp[StringLength - 2][Times - 1] - epsilon * r_square * Msquare * (y_Amp[StringLength - 3][Times - 1] - y_Amp[StringLength - 1][Times - 1]);

}

int main()
{
	initString();
	double data[TimeStep];	
	for (int j = 2; j < TimeStep; ++j)
	{
		propagate(j);
		data[j] = y_Amp[4][j];
	}

	// gsl_fft_real_radix2_transform(data, 1, 8192);
	double count,numIwant;	
	ofstream myfile;
	myfile.open ("PianoC7.dat");
	for(int i = 0; i < TimeStep; i++)
	{
		count = i * 0.152;
		// numIwant = sqrt((data[i] * data[i] + data[TimeStep - i - 1] * data[TimeStep - i - 1]) / 8192);
		myfile <<count<< "    " << data[i] <<endl;
	}

	myfile.close();
	return 0;
}
