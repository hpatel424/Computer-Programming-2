

//Harry Patel

#include<iostream>
#include<string>
#include<list>
#include<map>

using namespace std;

bool isEmailValid(string arg);

int main() {

	string email;
	char userResponse = 'y';
	do{
		cout << "Enter email: ";
		getline(cin, email);

	try {
		(isEmailValid(email));
		cout << email << endl;
		cout << "Valid!" << endl;
	}
	catch (exception e) {
		cout << "Error Message: " << e.what() << endl;
	}
	
	cout << "\nRun again? (y or n)";
	cin >> userResponse;
	cin.ignore();

	} while (userResponse == 'y');

	system("pause");
	return 0;
}


bool isEmailValid(string arg) {

	list<string> validEmailExtensions = { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu" };
	list<string>::iterator itr;

	string exe;
	int pos = 0;

	for (int i = 0; i < arg.length(); i++) {
		if (arg[i] == '@')
			pos = i;
	}
	if (pos == 0) {
		throw exception("Error 404! @ NOT found");
	}
	exe = arg.substr(pos);

	for (itr = validEmailExtensions.begin(); itr != validEmailExtensions.end(); itr++) {
		if (exe == (*itr)) {
			return true;
		}

	}
	throw exception("Invalid Email Extension");
	return false;
}
	
	/*if (exe == "@gmail.com" || exe == "@aol.com" || exe == "@cos.edu" || exe == "@giant.cos.edu") {
		return true;
	}
	else {
		throw exception("Invalid Email Extension");
	}*/
	

	
