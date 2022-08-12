

//Harry Patel

#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159;

//Abstract base class shape
class Shape {
private:
	string color;

public:
	Shape(string argColor = "transparent");

	void setColor(string);
	string getColor(void);

	virtual double calculatePerimeter() = 0;
	virtual double calculateArea() = 0;
	virtual void displayInfo(void);

};

class Polygon : public Shape {
private:
	int numberOfSides;
	double length;
	string name;

public:
	Polygon(string argColor, int argSides = 3, double argl = 1.0, string argName = "");

	void setsides(int argsides);
	int getsides(void);

	void setLength(double argl);
	double getLength(void);

	void setName(string argName);
	string getName(void);

	double calculatePerimeter();
	double calculateArea();
	void displayInfo(void);

};


class Node {
public:
	Shape* item;
	Node* nextptr;
	Node* prevptr;
	
};

int main() {

	Shape* myPoly;

	Node* head;
	Node* curNode = new Node();

	head = curNode;
	//Populate the first Node
	curNode->prevptr = nullptr;
	curNode->item = new Polygon("Red", 3, 5, "TRIANGLE");
	curNode->nextptr = new Node();

	//need set next prev pointer to curNode
	curNode->nextptr->prevptr = curNode;

	//iterate
	curNode = curNode->nextptr;
	curNode->item = new Polygon("Blue", 4, 3.5, "Dimond");
	curNode->nextptr = new Node();

	//need set next prev pointer to curNode
	curNode->nextptr->prevptr = curNode;

	//iterate
	curNode = curNode->nextptr;
	curNode->item = new Polygon("Orange", 5, 6, "Pentagon");
	curNode->nextptr = nullptr;

	curNode = head;
	/*
	//add a Node
	Node* temp = new Node();
	temp->item = new Polygon("yellow");
	temp->prevptr = curNode;
	temp->nextptr = curNode->nextptr;
	curNode->nextptr->prevptr = temp;
	curNode->nextptr = temp;
	*/
	
	

	while (curNode->nextptr != nullptr) {

		(curNode->item)->displayInfo();
		curNode = curNode->nextptr;
	}
	cout << endl;
	curNode->item->displayInfo();

	while (curNode->nextptr != nullptr) {
		 curNode = curNode->nextptr;
	};
	// now tempNodePtr is at the end;
	cout << "Reverse ******************\n" << endl;
	while (curNode->prevptr != nullptr) {
		curNode->item->displayInfo();
		curNode = curNode->prevptr;
	};
	 curNode->item->displayInfo();
	cout << "******************" << endl;

	//Memory Management
	curNode = head;
	head = head->nextptr;
	delete curNode;
	curNode = nullptr;

	curNode = head;
	head = head->nextptr;
	delete curNode;
	curNode = nullptr;

	curNode = head;
	head = head->nextptr;
	delete curNode;
	curNode = nullptr;

	curNode = NULL;
	
	system("pause");
	return 0;
}


Shape::Shape(string argColor) {
	setColor(argColor);
}
void Shape::setColor(string arg) {
	color = arg;
}
string Shape::getColor(void) {
	return(color);
}
void Shape::displayInfo(void) {
	cout << "Color: " << getColor() << endl;
}


Polygon::Polygon(string argColor, int argSides, double argl, string argName) : Shape(argColor) {
	Shape::setColor(argColor);

	setsides(argSides);
	setLength(argl);
	setName(argName);
}

void Polygon::setsides(int argsides) {
	if (argsides < 3)
		numberOfSides = 3;
	else
		numberOfSides = argsides;
}
int Polygon::getsides(void) {
	return numberOfSides;
}

void Polygon::setLength(double argl) {
	if (argl < 0)
		length = 0;
	else
		length = argl;
}
double Polygon::getLength(void) {
	return length;
}

void Polygon::setName(string argName) {
	int s = getsides();

	if (s == 3)
		name = "Triangle";
	else if (s == 4)
		name = "Square";
	else if (s == 5)
		name = "Pentagon";
	else if (s == 6)
		name = "Hexagon";
	else
		name = argName;
}
string Polygon::getName(void) {
	return name;
}


double Polygon::calculatePerimeter() {
	return getsides() * getLength();
}
double Polygon::calculateArea() {
	int s = getsides();
	double l = getLength();
	return s * (l * l) / (4 * tan(PI / s));
}

void Polygon::displayInfo(void) {

	cout << "Name: " << getName() << endl;
	Shape::displayInfo();
	cout << "Number of Sides = " << getsides() << endl;
	cout << "Length = " << getLength() << " unit " << endl;
	cout << "Perimeter = " << calculatePerimeter() << " unit " << endl;
	cout << "Area = " << calculateArea() << " square unit " << endl << endl;
}