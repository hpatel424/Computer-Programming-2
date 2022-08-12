
//Harry Patel

#include <iostream>
#include<string>

using namespace std;

int binarySearch(string a[], string target, int first, int last);

int main() {

		string a[] = { "student", "employee", "sportsman", "Athlete" };
		string t = "sportsman";
		int l = 4;
		int f = 0;
		int result = binarySearch(a, t, f, l);

		if (result == -1)
			cout << "Error 404! item not found " << endl;
		else
			cout << "Item found at index: " << result << endl;
	
	system("pause");
	return 0;
}

int binarySearch(string a[], string target, int first, int last)
{
	int index = 0;

	if (first > last) {
		index = -1;
	}
	else {
		int mid = first + (last - first) / 2;

		if (target == a[mid])
			index = mid;
		else if (target < a[mid])
			index = binarySearch(a, target, first, mid - 1);
		else
			index = binarySearch(a, target, mid + 1, last);

	}
	return index;
}
