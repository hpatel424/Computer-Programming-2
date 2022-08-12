
//Harry Patel

#include <iostream>

using namespace std;

template<typename T>
void print(T* arr, int size);
template <typename T>
void merge(T* m, T* a1, T* a2, int size, int size1, int size2);


int main() {

	int const size1 = 5;
	int const size2 = 5;
	int const size = size1 + size2;

	int a[size1] = { 1,2,3,4,5 };
	int array[size2] = { 6,7,8,9,10 };

	int merged[size];

	merge<int>(merged, a, array, size, size1, size2);
	print<int>(merged, size);


	system("pause");
	return 0;
}

template <typename T>
void merge(T* m,T*a1,T*a2, int size, int size1, int size2) {
	for (int i = 0; i < size1; i++) {
		m[i] = a1[i];
	}
	for (int i = 0, k = size1; k < size && i < size2; i++, k++) {
		m[k] = a2[i];
	}

}

template<typename T>
void print(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}