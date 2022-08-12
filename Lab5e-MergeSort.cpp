

//Harry Patel

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right);
vector<int> mergeSort(vector<int> vec);
void print(vector<int> vec);

int main() {

    srand(time(0));

    vector<int> myVector;

    for (int i = 0; i < 6; i++) {
        myVector.push_back(rand() % 10);
    }

    cout << "Size = " << myVector.size() << endl;

    cout << "Original: " << endl;
    print(myVector);

    vector<int>sorted = mergeSort(myVector);

    cout << "Sorted: " << endl;
    print(sorted);

   

    system("pause");
    return 0;
}

vector<int> merge(vector<int> left, vector<int> right) {
   
    int leftCount = 0;
    int rightCount = 0;

    vector<int> results;

    bool useLeft;
    for (int i = 0; i < left.size() + right.size(); i++) {
        if (leftCount < left.size()) {
            if (rightCount < right.size()) {
                useLeft = (left[leftCount] < right[rightCount]);
            }
            else {
                useLeft = true;
            }
        }
        else {
            useLeft = false;
        }

        if (useLeft) {
            results.push_back(left[leftCount]);
            if (leftCount < left.size()) {
                leftCount++;
            }
        }
        else {
            results.push_back(right[rightCount]);
            if (rightCount < right.size()) {
                rightCount++;
            }
        }
    }
    return results;
}

vector<int> mergeSort(vector<int> vec) {

    if (vec.size() <= 1)
        return vec;

    vector<int> left, right, result;
    int middle = (vec.size() + 1) / 2;

    for (int i = 0; i < middle; i++) {
        left.push_back(vec[i]);
    }

    for (int i = middle; i < vec.size(); i++) {
        right.push_back(vec[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);
    return result;
}


void print(vector<int> vec) {

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}