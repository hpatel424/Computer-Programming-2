

//Harry Patel

// Notes: Singly Linked List 
// An abstraction of an array.

#include <iostream> 
#include <string>
using namespace std;

// Class that defines the node object
class Node {
private:
	string item;
	Node* nextPtr;

public:
	//constructors
	Node();
	Node(string);
	Node(string, Node*);

	//Accessor Methods
	void setItem(string);
	string getItem();
	void setNextPtr(Node*);
	Node* getNextPtr();

};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);

int main(void) {

	char response = 'y';
	string userString;
	int cnt = 0;

	// 1. Note the difference between a pointer and Node Object
	Node* headPtr = new Node("");
	Node myNode; //compile time instance

	Node* curNodePtr = headPtr; //temp curNodePtr is often called the iterator

	// 2. Hard code a singly linked list with the head pointer above.

	do {
		cout << "Enter String: ";
		getline(cin, userString);

		curNodePtr->setNextPtr(new Node(userString));
		curNodePtr = curNodePtr->getNextPtr();

		//printStringList(headPtr);

		//cnt = cnt + 1;

		cout << "Enter agin?";
		cin >> response;
		cin.ignore();

	} while (response == 'y');

	printStringList(headPtr);


	// 3. Memory Management (Clean-up when done from front)

	while (headPtr != NULL) {
		curNodePtr = headPtr;
		headPtr = headPtr->getNextPtr();
		delete curNodePtr;
	}
	headPtr = nullptr;

	printStringList(headPtr);


	system("pause");
	return (0);
}

void printStringList(Node* beginningNodePtr) {

	Node* tempNodePtr = beginningNodePtr;

	cout << "******************" << endl;
	if (tempNodePtr == nullptr) {
		cout << "List Empty" << endl;
	}
	else {
		while (tempNodePtr->getNextPtr() != nullptr) {

			cout << tempNodePtr->getItem() << endl;
			tempNodePtr = tempNodePtr->getNextPtr();

		};
		cout << tempNodePtr->getItem() << endl;

	}
	cout << "******************" << endl;

}


//Node Implementation
Node::Node()
{
	setItem(""); //default to empty string
	setNextPtr(nullptr); //default to null pointer
}

Node::Node(string arg)
{
	setItem(arg);
	setNextPtr(nullptr);
}

Node::Node(string arg, Node* argPtr)
{
	setItem(arg);
	setNextPtr(argPtr);
}

void Node::setItem(string arg)
{
	item = arg;
}

string Node::getItem()
{
	return item;
}

void Node::setNextPtr(Node* argPtr)
{
	nextPtr = argPtr;
}

Node* Node::getNextPtr()
{
	return nextPtr;
}