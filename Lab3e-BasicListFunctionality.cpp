

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
void popList(Node* headPtr);
void deleteListItem(Node*, Node*);
void insertListItem(Node* curNodePtr, Node* newNodePtr);


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

	cout << "Original List" << endl;
	printStringList(headPtr);

	popList(headPtr);
	cout << "Last Node deleted " << endl;
	printStringList(headPtr);
	
	curNodePtr = headPtr;	//This will insert the newNode after "Mary".
	insertListItem(curNodePtr, newNodePtr);
	cout << "Node inserted " << endl;
	printStringList(headPtr);
	
	deleteListItem(headPtr, curNodePtr);	//This will delete the curNodePtr which we inserted above.
	cout << "Deleted the given Node " << endl;
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

void popList(Node* headPtr) {
	Node* temp = headPtr;

	while (temp->getNextPtr()->getNextPtr() != nullptr) {
		temp = temp->getNextPtr()->getNextPtr();
	}
	delete temp->getNextPtr();
	temp->setNextPtr(nullptr);
}

void deleteListItem(Node* curNodePtr, Node* headPtr) {
	Node* temp;
	temp = curNodePtr->getNextPtr();
	curNodePtr->getItem() = temp->getItem();
	curNodePtr->setNextPtr(temp->getNextPtr());
	delete temp;
	temp = nullptr;
}


void insertListItem(Node* curNodePtr, Node* newNodePtr) {
	Node* temp;
	if (curNodePtr == nullptr) {
		return;
	}
	else {
		temp = curNodePtr->getNextPtr();
		newNodePtr = curNodePtr;
		newNodePtr->setNextPtr(new Node("Inserted"));
		newNodePtr = newNodePtr->getNextPtr();
		newNodePtr->setNextPtr(temp);
	}
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