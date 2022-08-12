

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
Node* reverseNode(Node* headPtr);

int main() {

	Node* headPtr = nullptr;
	Node myNode;
	Node* curNodePtr = nullptr;
	Node* newNodePtr = nullptr;

	curNodePtr = new Node("Mary");
	headPtr = curNodePtr;

	curNodePtr->setNextPtr(new Node("Bill"));
	curNodePtr = curNodePtr->getNextPtr();

	curNodePtr->setNextPtr(new Node("James"));
	curNodePtr = curNodePtr->getNextPtr();

	curNodePtr->setNextPtr(new Node("Aubrey"));
	curNodePtr = curNodePtr->getNextPtr();

	curNodePtr->setNextPtr(new Node("Mac"));
	curNodePtr = curNodePtr->getNextPtr();

	cout << "Original list" << endl;
	printStringList(headPtr);
	
	cout << "Reversed list" << endl;
	reverseNode(headPtr);
	headPtr = curNodePtr;
	printStringList(headPtr);


	// 3. Memory Management (Clean-up when done from front)
	while (headPtr != NULL) {
		curNodePtr = headPtr;
		headPtr = headPtr->getNextPtr();
		delete curNodePtr;
	}
	headPtr = nullptr; //both should be nullptr at the end
	printStringList(headPtr);

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

Node* reverseNode(Node* headPtr) {
	Node* prevPtr = nullptr;
	Node* nextPtr = nullptr;
	Node* currNode = nullptr;

	currNode = headPtr;

	while (currNode != nullptr){
		nextPtr = currNode->getNextPtr();
		currNode->setNextPtr(prevPtr);
		prevPtr = currNode;
		currNode = nextPtr;
	}
	return prevPtr;
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