#include <cmath>
#include <iostream>

using namespace std;

//subj function
double f(double x) { 
	return log((1 - x) / (1 + x));
}

//derivative of subj function
double f1(double x) { 
	return 2.0 / (pow(x, 2.0) - 1);
}

//second derivative of subj function
double f2(double x) { 
	return (-4.0 * x) /pow((pow(x,2.0) - 1),2.0);
}

//find root of subj function through dichotomy method
double dichotomy(double l, double r, double accuracy) { 
	double left=l, right=r, tmp=0;
	while (abs(f(left) - f(right)) > accuracy) {
		tmp = (left + right) / 2.0;
		if (f(tmp) * f(left) <= 0)
			right = tmp;
		else
			left = tmp;
	}
	return tmp;
}

//find root of subj function through chords method
double chords(double l, double r, double accuracy) {
	double left = l, right = r;
	if (f(left) * f2(left) > 0) {
		while (abs(f(right)) > accuracy) 
			right = right - (f(right) * (right - left)) / (f(right) - f(left));
		return right;
	}
	else {
		while (abs(f(left)) > accuracy) 
			left = left - (f(left) * (right - left)) / (f(right) - f(left));
		return left;
	}
}

//find root of subj function through newtons method
double newtons(double l, double r, double accuracy) {
	double left = l, right = r, tmp;
	if (f(left) * f2(left) > 0)
		tmp = right;
	else
		tmp = left;
	while (abs(f(tmp)) > accuracy) {
		tmp -= f(tmp) / f1(tmp);
	}
	return tmp;
}

int main(){
	double a, b, accuracy;
	/*cout << "Enter a and b: ";
	cin >> a >> b;
	cout << "Enter accuracy: ";
	cin >> accuracy;*/
	a = -0.6; b = 0.3; accuracy = 0.001;
	cout << "Root by dichotomy: " << dichotomy(a, b, accuracy) << endl;
	cout << "Root by chords: " << chords(a, b, accuracy) << endl;
	cout << "Root by newtons: " << newtons(a, b, accuracy) << endl;
	return 0;
}