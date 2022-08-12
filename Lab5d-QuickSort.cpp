

//Harry Patel

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& vec, int low, int high);
void quickSort(vector<int>& vec, int low, int high);
void print(vector<int> vec);

int main() {

    vector<int> myVector = { 9,8,7,6,5,4,3,2,1,0 };

    cout << "Original: " << endl;
    print(myVector);

    quickSort(myVector, 0, myVector.size() - 1);

    cout << "Sorted: " << endl;
    print(myVector);

    cout << "Size = " << myVector.size() << endl;

	system("pause");
	return 0;
}


int partition(vector<int>& vec, int low, int high){

    int pivot = vec[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (vec[j] <= pivot) {
            i++; 
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector<int>& vec, int low, int high){

    if (low < high) {

        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}


void print(vector<int> vec){

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}