

//Harry Patel


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Button {
public:
    virtual void print(void) = 0;
};

class Left :public Button {
    int counter = 0;
public:
    void print(void);
    virtual int leftCounter();
};
class L1 :public Left {
    int counter = 0;
public:
    void print(void);
    int leftCounter();
};
class L2 : public Left {
    int counter = 0;
public:
    void print(void);
    int leftCounter();
};

class Right : public Button {
    int counter = 0;
public:
    void print(void);
    virtual int rightCounter();
};
class R1 :public Right {
    int counter = 0;
public:
    void print(void);
    int rightCounter();
};
class R2 :public Right {
    int counter = 0;
public:
    void print(void);
    int rightCounter();
};


int main() {

    vector<Button*> btnPtr;

    btnPtr.push_back(new L1());
    btnPtr.push_back(new L2());

    btnPtr.push_back(new R1());
    btnPtr.push_back(new R2());
    
    for (int i = 0; i < btnPtr.size(); i++) {
        cout << "btnPtr " << i + 1 << ": " << typeid(*btnPtr[i]).name() << endl;
        //Polymorphism here
        btnPtr[i]->print();

        if (i == 3) {
            btnPtr[i]->print();
            btnPtr[i]->print();
        }
        cout << endl;
    }

    //Memory Management

    while (!btnPtr.empty()) {
        delete btnPtr.back(); //deallocate memory
        btnPtr.pop_back(); // pop address off vector
    }

    system("pause");
    return 0;
}

void Left::print(void) {
    cout << "Left Button Pressed" << endl;
    cout << "Number of times Clicked = " << Left::leftCounter() << endl;
}

void L1::print(void) {
    cout << "L1 Button Pressed" << endl;
    cout << "Number of times Clicked = " << L1::leftCounter() << endl;
}
void L2::print(void) {
    cout << "L2 Button Pressed" << endl;
    cout << "Number of times Clicked = " << L2::leftCounter() << endl;
}

void Right::print(void) {
    cout << "Right Button Inside" << endl;
    cout << "Number of times Clicked = " << Right::rightCounter() << endl;
}

void R1::print(void) {
    cout << "R1 Button Pressed" << endl;
    cout << "Number of times Clicked = " << R1::rightCounter() << endl;
}
void R2::print(void) {
    cout << "R2 Button Pressed" << endl;
    cout << "Number of times Clicked = " << R2::rightCounter() << endl;
}

int Left::leftCounter() {
    counter = counter + 1;
    return counter;
}
int L1::leftCounter() {
    counter = counter + 1;
    return counter;
}
int L2::leftCounter() {
    counter = counter + 1;
    return counter;
}
int Right::rightCounter() {
    counter = counter + 1;
    return counter;
}
int R1::rightCounter() {
    counter = counter + 1;
    return counter;
}
int R2::rightCounter() {
    counter = counter + 1;
    return counter;
}