

//Harry Patel

/*
	create a char type stack and populate with the user string characters.
	and reverse the string using while loop.
	check if the original string is same as reversed and if it is than its palindrome
	if not than its NOT palindrome and if it is just one character or empty space its palindrome.


*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isPalindrome(string arg1);

int main() {
	
	cout << "Check Palindrome\n" << endl;
	char response = 'y';
	string userInput;
	

	do {
		cout << "Enter string: ";
		getline(cin, userInput);

		
		if (isPalindrome(userInput) == true) {
			cout << userInput << " is Palindrome" << endl;
		}
		else {
			cout << userInput << " is NOT Palindrome" << endl;
		}
		cout << endl;

		cout << "Run again (y or n)?";
		cin >> response;
		cin.ignore();
	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}

bool isPalindrome(string arg) {

	stack<char> input;
	string r;

	for (int i = 0; i < arg.size(); i++) {
		input.push(arg[i]);
	}
	while (!input.empty()) {
		r = r + input.top();
		input.pop();
	}
	if (r == arg) {
		return true;
	}
	else if (arg.size() == 1 || arg.empty() == true) {
		return true;
	}
	else {
		return false;
	}
}
