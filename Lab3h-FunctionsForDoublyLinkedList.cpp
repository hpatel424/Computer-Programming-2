

//Harry Patel

#include<iostream>	
#include <string>
#include <vector>

using namespace std;

class Node {
private:
	string item;
	Node* nextPtr;
	Node* prevPtr;

public:
	//constructors
	Node();
	Node(string);
	Node(string, Node*);
	Node(string, Node*, Node*);

	//Accessor Methods
	void setItem(string);
	string getItem();
	void setNextPtr(Node*);
	Node* getNextPtr();
	void setPrevPtr(Node*);
	Node* getPrevPtr();

};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);
void printStringListReverse(Node* beginningNodePtr);
void deleteEnd(Node*);
void deleteNode(Node* head, Node* curNodePtr);
void sortedInsert(Node* head_ref, Node* newNode);

int main() {

	Node* headPtr = nullptr;
	Node* curNodePtr = nullptr;
	Node* tempPtr = nullptr;

	curNodePtr = new Node("Mary");
	headPtr = curNodePtr;

	//populate the second node
	tempPtr = new Node("Bill");
	tempPtr->setPrevPtr(curNodePtr);
	curNodePtr->setNextPtr(tempPtr);
	curNodePtr = curNodePtr->getNextPtr();

	//populate the third node
	tempPtr = new Node("James");
	tempPtr->setPrevPtr(curNodePtr);
	curNodePtr->setNextPtr(tempPtr);
	curNodePtr = curNodePtr->getNextPtr();

	//populate the fourth node
	tempPtr = new Node("Aubrey");
	tempPtr->setPrevPtr(curNodePtr);
	curNodePtr->setNextPtr(tempPtr);
	curNodePtr = curNodePtr->getNextPtr();

	cout << "Original List Printed Forward" << endl;
	printStringList(headPtr);

	cout << "Original List Printed Reversed" << endl;
	printStringListReverse(headPtr);

	deleteNode(headPtr, tempPtr->getPrevPtr());	//given Node is "James"
	cout << "Deleted the given Node (given Node is James)" << endl;
	printStringList(headPtr);

	deleteEnd(headPtr);
	cout << "Last Node deleted" << endl;
	printStringList(headPtr);

	sortedInsert(headPtr, new Node("insert"));
	cout << "Node inserted" << endl;
	printStringList(headPtr);

	//Memory Management
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

	cout << "Forward ******************" << endl;
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
void printStringListReverse(Node* beginningNodePtr) {

	Node* tempNodePtr = beginningNodePtr;

	if (tempNodePtr == nullptr) {
		cout << "List Empty" << endl;
	}
	else {
		while (tempNodePtr->getNextPtr() != nullptr) {
			tempNodePtr = tempNodePtr->getNextPtr();
		};
		// now tempNodePtr is at the end;
		cout << "Reverse ******************" << endl;
		while (tempNodePtr->getPrevPtr() != nullptr) {
			cout << tempNodePtr->getItem() << endl;
			tempNodePtr = tempNodePtr->getPrevPtr();
		};
		cout << tempNodePtr->getItem() << endl;
		cout << "******************" << endl;
	}
}

void deleteEnd(Node* headPtr) {
	Node* ptr , *prev = nullptr;
	
	if (headPtr == NULL)
		return;
	else if (headPtr->getNextPtr() == NULL) {
		ptr = headPtr;
		headPtr = nullptr;
		delete(ptr);
	}
	else {
		ptr = headPtr;
		while (ptr->getNextPtr() != nullptr) {
			prev = ptr;
			ptr = ptr->getNextPtr();

		}
		delete(ptr);
		prev->setNextPtr(nullptr);
	}
}
void deleteNode(Node* head, Node* curNodePtr){
	if (head == NULL || curNodePtr == NULL) {
		return;
	}
	if (head == curNodePtr) {
		head = curNodePtr->getNextPtr();
	}
	if (curNodePtr->getNextPtr() != NULL) {
		curNodePtr->getNextPtr()->setPrevPtr(curNodePtr->getPrevPtr());
	}

	if (curNodePtr->getPrevPtr() != NULL) {
		curNodePtr->getPrevPtr()->setNextPtr(curNodePtr->getNextPtr());
	}
	delete(curNodePtr);
}


void sortedInsert(Node* head, Node* newNode)
{
	Node* current;

	if (head == NULL) {
		head = newNode;
	}

	else if ((head)->getItem() >= newNode->getItem()) {
		newNode->setNextPtr(head);
		newNode->getNextPtr()->setPrevPtr(newNode);
		head = newNode;
	}
	else {
		current = head;

		while (current->getNextPtr() != NULL &&
			current->getNextPtr()->getItem() < newNode->getItem()) {
			current = current->getNextPtr();
		}
		newNode->setNextPtr(current->getNextPtr());

		if (current->getNextPtr() != NULL)
			newNode->getNextPtr()->setPrevPtr(newNode);

		current->setNextPtr(newNode);
		newNode->setPrevPtr(current);
	}
}

//Node Implementation
Node::Node()
{
	setItem(""); //default to empty string
	setNextPtr(nullptr); //default to null pointer
	setPrevPtr(nullptr);
}

Node::Node(string arg)
{
	setItem(arg);
	setNextPtr(nullptr);
	setPrevPtr(nullptr);

}

Node::Node(string arg, Node* argPtr)
{
	setItem(arg);
	setNextPtr(argPtr);
	setPrevPtr(nullptr);
}
Node::Node(string arg, Node* argNextPtr, Node* argPrevPtr)
{
	setItem(arg);
	setNextPtr(argNextPtr);
	setPrevPtr(argPrevPtr);
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

void Node::setPrevPtr(Node* arg)
{
	prevPtr = arg;
}

Node* Node::getPrevPtr()
{
	return prevPtr;
}