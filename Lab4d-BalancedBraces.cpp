

//Harry Patel

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool checkBraces(string arg);

int main() {

	string input;
	char response = 'y';

	do {
		cout << "Enter a string to check balanced brackets: ";
		getline(cin, input);

		bool result = checkBraces(input);

		if (result == true) {
			cout << input << " = Balanced" << endl;
		}
		else {
			cout << input << " = NOT Balanced" << endl;
		}
		cout << endl;

		cout << "One more string (y or n)?";
		cin >> response;
		cin.ignore();

	} while (response == 'y' || response == 'Y');
	

	system("pause");
	return 0;
}



bool checkBraces(string arg) {

	stack<char> a;
	bool balanced = true;
	int i = 0;
	

	while (balanced && i < arg.length()) {
		
		char c = arg[i];
		i++;

		if (c == '{' || c == '(' || c == '[') {
			if (c == '{') {
				a.push(char('{'));
			}
			if (c == '(') {
				a.push(char('('));
			}
			if (c == '[') {
				a.push(char('['));
			}
		}
		else if (arg[0] == ')' || arg[0] == '}' || arg[0] == ']') {
			return false;
		}
		else if (c == '}' || c == ')' || c == ']') {

			if (a.top() == '{' && c == '}') {
				a.pop();
			}
			else if (a.top() == '(' && c == ')') {
				a.pop();
			}
			else if (a.top() == '[' && c == ']') {
				a.pop();
			}
			else {
				return false;
			}
		}
		
		
	}
	if (balanced && a.empty()) {
		return true;
	}
	else {
		return false;
	}

}