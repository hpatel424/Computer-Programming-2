

//Harry Patel

#include<iostream>	
#include <string>

using namespace std;

class Node {
private:
	string item;
	Node* nextPtr;
public:
	Node();
	Node(string);
	Node(string, Node*);

	//Accessor Methods
	void setItem(string);
	string getItem();
	void setNextPtr(Node*);
	Node* getNextPtr();

};

void printStringList(Node* beginningNodePtr);
int size(Node* head);
void reverse(Node* head);

int main() {

	Node* headPtr = nullptr;
	Node myNode;
	Node* curNodePtr = nullptr;
	Node* newNodePtr = nullptr;

	cout << "Hard coded Linked List" << endl;
	curNodePtr = new Node("Mary");
	headPtr = curNodePtr;

	curNodePtr->setNextPtr(new Node("Bill"));
	cout << curNodePtr->getItem() << endl;
	curNodePtr = curNodePtr->getNextPtr();

	curNodePtr->setNextPtr(new Node("James"));
	cout << curNodePtr->getItem() << endl;
	curNodePtr = curNodePtr->getNextPtr();

	curNodePtr->setNextPtr(new Node("Aubrey"));
	cout << curNodePtr->getItem() << endl;
	curNodePtr = curNodePtr->getNextPtr();

	curNodePtr->setNextPtr(new Node("Mac"));
	cout << curNodePtr->getItem() << endl;
	curNodePtr = curNodePtr->getNextPtr();
	cout << curNodePtr->getItem() << endl;

	cout << "Original List print function" << endl;
	printStringList(headPtr);

	cout << "Size = " << size(headPtr) << endl;



	system("pause");
	return 0;
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

int size(Node* head) {
	int s = 0;
	if (head == nullptr) {
		return 0;
	}
	while (head != nullptr) {
		head = head->getNextPtr();
		s++;
	}
	return s;
}
/*void reverse(Node* head) {
	Node* temp, *prev;
	temp = head;
	while (temp != nullptr) {
		temp = temp->getNextPtr();
	}
}*/



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