
//Harry Patel

#include <iostream>
#include <string>

using namespace std;

template<typename T>
T returnMaximum(T arg, T arg2);

template<typename T>
T returnMinimum(T arg, T arg2);

template<typename T>
void print(T arg, T arg2);


int main() {

	char response;
	do {

		string x = "Harry";
		string y = "Mr redden";

		char a = 'a';
		char b = 'b';

		int v = 3;
		int w = 5;

		double c = 2.2;
		double d = 5.9;

		
		print<string>(x, y);
		print <int>(v, w);
		print<char>(a, b);
		print<double>(c, d);
		

		cout << "play again?";
		cin >> response;
	} while (response == 'y');

	return 0;
}

template<typename T>
T returnMaximum(T arg, T arg2) {
	if (arg >= arg2)
		return arg;
	else
		return arg2;
}

template<typename T>
T returnMinimum(T arg, T arg2) {
	if (arg <= arg2)
		return arg;
	else
		return arg2;

}
template<typename T>
void print(T arg, T arg2) {
	cout << "Max: " << returnMaximum(arg,arg2 ) << endl;
	cout << "Min: " << returnMinimum(arg, arg2) << endl;
	cout << endl;
}
