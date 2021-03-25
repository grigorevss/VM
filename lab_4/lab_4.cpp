#include <cmath>
#include <iostream>

using namespace std;

//subj function
double f(double x) {
	return (pow(x, 3) + 1.0) / (pow(x, 2) - x + 2);
}

//derivative of subj function
double f1(double x) {
	return (pow(x, 4) - 2 * pow(x, 3) + 6 * pow(x, 2) - 2 * x + 1) / pow(pow(x, 2) - x + 2, 2);
}

double LeftDiff(double x, double accuracy) {
	return (f(x) - f(x - accuracy)) / accuracy;
}

double RightDiff(double x, double accuracy) {
	return (f(x + accuracy) - f(x)) / accuracy;
}

double CentralDiff(double x, double accuracy) {
	return (f(x + accuracy) - f(x - accuracy)) / (2 * accuracy);
}

int main() {
	double a;
	a = 1; 
	for (double i = 0.1; i > 0.00000001; i *= 0.1) {
		cout << " Accuracy = " << i << endl;
		cout << " LeftDiff    result: " << LeftDiff(a, i) << endl;
		cout << " RightDiff   result: " << RightDiff(a, i) << endl;
		cout << " CentralDiff result: " << CentralDiff(a, i) << endl;
		cout << " Original    result: " << f1(a) << endl;
		cout << " ################################" << endl;
	}
	return 0;
}