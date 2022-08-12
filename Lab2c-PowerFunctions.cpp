

//Harry Patel
#include <iostream>
#include <cmath>
using namespace std;

double recursive(double, int);
double iterative(double, int);



int main()
{
	cout << "Recursive Method = " << recursive(5.5, 3) << endl << endl;


	cout << "Iterative Method = " << iterative(5, 2) << endl << endl;


	system("pause");
	return 0;
}
double recursive(double b, int e){
	if (e != 0)
		return (b * recursive(b, e - 1));
	else
		return 1;
}

double iterative(double b, int p) {
	int result = 1;

	while (p > 0) {
		result = result * b;
		p = p - 1;
	}
	return result;
}