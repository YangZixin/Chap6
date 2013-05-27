#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

const int LengthOfCapacitor = 10;
const double GridInterval = 0.1;
const int GridCheck = LengthOfCapacitor * 10;
double potential[GridCheck][GridCheck];
double temp_potential[GridCheck][GridCheck];
double delta_V;

void initializa_V()
{
    for (int i = 0; i < GridCheck; i++)
    {
        potential[i][0] = 1;
        potential[i][GridCheck-1] = -1;
    }
}

void update_V()
{
    for (int i = 1; i < GridCheck-1; i++)
    {
        for (int j = 1; j < GridCheck-1; j++)
        {
            temp_potential[i][j] = (potential[i-1][j]+potential[i+1][j]+potential[i][j-1]+potential[i][j+1]) / 4;
            delta_V += sqrt((potential[i][j]-temp_potential[i][j]) * (potential[i][j]-temp_potential[i][j]));
        }
    }
    for (int i = 1; i < GridCheck-1; i++)
    {
        for (int j = 1; j < GridCheck-1; j++)
        {
            potential[i][j]=temp_potential[i][j];
        }
    }
}

int laplace_calculate()
{
    int N_iter;
    double PermitErrorV = GridCheck * GridCheck * pow(10, -5);
    do
    {
        update_V;
        N_iter++;
    }
    while(delta_V > PermitErrorV);
    return N_iter;
}

int main()
{
	initializa_V();
    int N_iter = laplace_calculate();
    cout<<N_iter<<endl;
    return 0;
}