

//Harry Patel

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string args);

int main() {

	char response = 'y';
	//string s = "Hello World";
	string x = "";
	do {

		cout << "Enter a string" << endl;
		getline(cin, x);

		if (isPalindrome(x) == true) {
			cout << "Its is Palindrome" << endl;
		}
		else {
			cout << "NOT a Palindrome" << endl;
		}

		cout << "Run Again? ";
		cin >> response;
		cin.ignore();
	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}

bool isPalindrome(string args) {
	if (args.empty() == true || args.size() == 1) {
		return true;
	}
	else if (args[0] == args[args.size() - 1]) {
		return isPalindrome(args.substr(1, args.size() - 2));

	}
	else {
		return false;
	}
}