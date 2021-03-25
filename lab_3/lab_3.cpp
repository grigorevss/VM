#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <ctime> 

using namespace std;

//subj function
double f(double x) {
	return pow(cos(x), 4) * pow(sin(x), 3);
}

//left rectangles method
double LeftRect(double left, double right, int accuracy) {
	double result = 0, step;
	step = (left - right) / accuracy;
	for (int i = 0; i < accuracy; ++i) {
		result += step * f(left + (double)i * step);
	}
	return result;
}

//right rectangles method
double RightRect(double left, double right, int accuracy) {
	double result = 0, step;
	step = (left - right) / accuracy;
	for (int i = 1; i <= accuracy; ++i) {
		result += step * f(left + (double)i * step);
	}
	return result;
}

//trapeziums method
double Trapeze(double left, double right, int accuracy) {
	double result = 0.5 * (f(left) + f(right));
	double step = (left - right) / accuracy;
	for (int i = 1; i < accuracy; ++i) {
		result += f(left + (double)i * step);
	}
	return result * step;
}

int main() {
	clock_t start;
	double a, b, accuracy;
	a = 0; b = M_PI_2; accuracy = 10;
	for (int i = 10; i < 100000000; i *= 10) {
		cout << " Accuracy = " << i << endl;
		start = clock();
		cout << " LeftRect  result: " << LeftRect(a, b, i) << endl;
		cout << " LeftRect    time: " << (clock() - start) / 1000.0 << " s." << endl;
		start = clock();
		cout << " RightRect result: " << RightRect(a, b, i) << endl;
		cout << " RightRect   time: " << (clock() - start) / 1000.0 << " s." << endl;
		start = clock();
		cout << " Trapeze   result: " << Trapeze(a, b, i) << endl;
		cout << " Trapeze     time: " << (clock() - start) / 1000.0 << " s." << endl;
		cout << " ################################" << endl;
	}
	return 0;
}