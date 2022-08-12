

//Harry Patel

#include<iostream>
#include<string>
using namespace std;

template <typename T >
void print(T* arr, int size);
template <typename T >
void deleteElement(T* arr, int index, int size);

int main() {

	const int size = 5;
	int a[size] = { 1,2,3,4,5 };
	print<int>(a, size);
	cout << "\n" << endl;
	deleteElement<int>(a, 3, size);
	print<int>(a, size);
	cout << "\n" << endl;

	char as[size] = { 'A','b','c','D','E' };
	print<char>(as, size);
	cout << "\n" << endl;
	deleteElement<char>(as, 3, size);
	print<char>(as, size);
	cout << "\n" << endl;

	//index to delete
	//int index = 3;

	//start looping at the index to delete
	system("pause");
	return 0;
}
template <typename T >
void deleteElement(T* arr, int index, int size) {
	//WARNING: Does not work for non-built in data types.
	if (index >= size)
		return;
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}

	arr[size - 1] = NULL;
}

template <typename T >
void print(T* arr, int size) {
	//print
	for (int i = 0; i < size; i++) {
		cout << "Element " << i << ":  " << arr[i] << endl;
	}
}