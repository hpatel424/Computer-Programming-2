
//Harry Patel

#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

void function1(vector <int> a);
void function2(vector <int> a);

int main() {

	srand(time(0));
	
		const int size = 3;
		vector<int>v(size);

		for (int i = 0; i < size; i++) {
			v[i] = rand() % 10 + 1;
		}

		function1(v);
		cout << endl;
		function2(v);

		system("pause");
		return 0;
}
void function1(vector<int>a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}
void function2(vector <int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << "Value: " << a[i] << " ||  Address: " << int(&a[i]) << endl;
	}
}