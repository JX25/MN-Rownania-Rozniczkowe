#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

double funkcjaX(double x) { return 2 * x; };
double funkcjaXY(double x, double y) { return x / y; };


// przyklad dla funkcji dy/dx = 2x
void forwardEuler(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki.csv", ios::app);
	plik << "forward_euler" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i=0; x0 <= 10.0; x0 += dx,i++)
	{
		plik << x0 << ";" << y0 << endl;
		if(i%var==0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		y0 = y0 + dx * funkcjaX(x0);
	}	
	plik.close();
}

void forwardEulerXY(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki2.csv", ios::app);
	plik << "forward_eulerXY" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10.0; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if (i%var == 0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		y0 = y0 + dx * funkcjaXY(x0, y0);
	}
	plik.close();
}

void backwardEuler(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki.csv", ios::app);
	plik << "backward_euler" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if(i%var==0)cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		y0 = y0 + dx * funkcjaX(x0 + dx);
	}
	plik.close();
}

void directIteration(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki.csv", ios::app);
	plik << "direct" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if(i%var==0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		double predictor = y0 + dx * funkcjaX(x0 + dx);
		y0 = y0 + dx * funkcjaX(x0 + dx);
	}
	plik.close();
}

void directIterationXY(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki2.csv", ios::app);
	plik << "direct XY" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if (i%var == 0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		double predictor = y0 + dx * funkcjaXY(x0 + dx, y0);
		y0 = y0 + dx * funkcjaXY(x0 + dx, predictor);
	}
	plik.close();
}

void improvedEuler(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki.csv", ios::app);
	plik << "improved euler" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if(i%var==0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		double predictor = y0 + dx * funkcjaX(x0);
		double corector = y0 + dx * funkcjaX(x0 + dx);
		y0 = (predictor + corector) / 2.0;
	}
	plik.close();
}

void improvedEulerXY(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki2.csv", ios::app);
	plik << "improved XY" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if (i%var == 0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		double predictor = y0 + dx * funkcjaXY(x0, y0);
		double corector = y0 + dx * funkcjaXY(x0 + dx, predictor);
		y0 = (predictor + corector) / 2.0;
	}
	plik.close();
}

void rungeKutta(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki.csv", ios::app);
	plik << "runge kutta" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if(i%var==0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		double k1 = dx * funkcjaX(x0);
		double k2 = dx * funkcjaX(x0 + dx / 2.0);
		double k3 = dx * funkcjaX(x0 + dx / 2.0);
		double k4 = dx * funkcjaX(x0 + dx);
		y0 = y0 + 1.0 / 6.0*(k1 + 2 * k2 + 2 * k3 + k4);
	}
	plik.close();
}

void rungeKuttaXY(double x0, double y0, double dx)
{
	fstream plik;
	plik.open("rozniczki2.csv", ios::app);
	plik << "runge kutta xy" << endl;
	int var;
	if (dx == 0.5) var = 2;
	else var = 10;
	for (int i = 0; x0 <= 10; x0 += dx, i++)
	{
		plik << x0 << ";" << y0 << endl;
		if (i%var == 0) cout << "x=" << x0 << "\t" << "y=" << y0 << endl;
		double k1 = dx * funkcjaXY(x0, y0);
		double k2 = dx * funkcjaXY(x0 + dx / 2.0, y0 + 0.5*k1);
		double k3 = dx * funkcjaXY(x0 + dx / 2.0, y0 + 0.5*k2);
		double k4 = dx * funkcjaXY(x0 + dx, y0 + k3);
		y0 = y0 + 1.0 / 6.0*(k1 + 2 * k2 + 2 * k3 + k4);
	}
	plik.close();
}



int main()
{
	double delta1 = 0.5;
	double delta2 = 0.1;
	
	cout << "FORWARD EULER" << endl;
	forwardEuler(0, 0, delta1);
	cout << endl;
	forwardEuler(0, 0, delta2);
	cout << "BACKWARD EULER" << endl;
	backwardEuler(0, 0, delta1);
	cout << endl;
	backwardEuler(0, 0, delta2);
	cout << "Direct iteration" << endl;
	directIteration(0, 0, delta1);
	cout << endl;
	directIteration(0, 0, delta2);
	cout << "Improved Euler" << endl;
	improvedEuler(0, 0, delta1);
	cout << endl;
	improvedEuler(0, 0, delta2);
	cout << "RUNGE KUTTA" << endl;
	rungeKutta(0, 0, delta1);
	cout << endl;
	rungeKutta(0, 0, delta2);

	cout << "FE" << endl;
	forwardEulerXY(0, 1, delta1);
	forwardEulerXY(0, 1, delta2);
	cout << "DI" << endl;
	directIterationXY(0, 1, delta1);
	directIterationXY(0, 1, delta2);
	cout << "IE" << endl;
	improvedEulerXY(0, 1, delta1);
	improvedEulerXY(0, 1, delta2);
	cout << "RK" << endl;
	rungeKuttaXY(0, 1, delta1);
	rungeKuttaXY(0, 1, delta2);


	getchar();
	return 0;
}