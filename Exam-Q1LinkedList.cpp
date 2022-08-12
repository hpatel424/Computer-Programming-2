

//Harry Patel

#include<iostream>

using namespace std;

class Node {
public:
	int x;
	int y;
	Node* next;

};

void print(Node* head);
int main() {

	Node* head = nullptr;
	Node* temp = nullptr;
	

	temp = new Node();
	temp->x = 1;
	temp->y = 2;
	
	head = temp;

	temp->next = new Node();
	temp = temp->next;
	temp->x = 3;
	temp->y = 4;

	temp->next = head;

	print(head);

	temp = head;
	head = head->next;
	delete temp->next;
	head = nullptr;

	print(head);

	system("pause");
	return 0;
}

void print(Node* head) {
	Node* temp = head;
	if (temp == nullptr) {
		cout << "List Empty" << endl;
	}
	else {

		cout << "(x,y)" << endl;

		while (temp->next != head) {
			cout << "(" << temp->x << "," << temp->y << ") " << endl;
			temp = temp->next;
		}
		cout << "(" << temp->x << "," << temp->y << ") " << endl;
	}
}