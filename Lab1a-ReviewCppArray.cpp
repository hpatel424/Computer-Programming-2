

//Harry Patel

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void random(int a[], int size);
void pointer(int a[], int size);

int main() {
	srand(time(0));
	char response = 'y';
	do {
		const int size = 15;
		int arr[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 2 * (rand() % 50 + 1);
			
		}
		random(arr, 15);
		cout << endl;
		pointer(arr, 15);


		cout << "Run again? : ";
		cin >> response;
	} while (response == 'y');
	
	system("pause");
	return 0;
}
void random(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") " << a[i] << " --- Address: " << &a[i] << endl;
	}
}
void pointer(int a[], int size) {
	int* ptr = &a[0];
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") " << *ptr << " --- Address : " << ptr << endl;
		ptr++;
	}
}