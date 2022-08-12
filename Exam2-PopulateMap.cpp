

//Harry Patel

#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

struct Person {
	string name;
	int age;

	Person(string arg1, int arg2) {
		name = arg1;
		age = arg2;
	}
};

int main() {

	map<string, vector<Person*>> categoryMap;
	map<string, vector<Person*>>::iterator itr;

	char response = 'y';
	string category, inputName;
	int inputAge = 0;

	vector<Person*> managers = { new Person("Jaddu",25),new Person("Modi",26) };
	vector<Person*> engineers = { new Person("Ashwin",35),new Person("Anil",50) };
	vector<Person*> customers = { new Person("Warner",25),new Person("Suresh",30) };

	//customers.push_back(new Person("Name", 30));

	categoryMap["managers"] = managers;
	categoryMap["engineers"] = engineers;
	categoryMap["customers"] = customers;

	itr = categoryMap.begin();

	//cout << categoryMap["managers"][0]->name << endl;

	while (itr != categoryMap.end()) {
		cout << "Key: " << (*itr).first <<":------------"<< endl;
		for (int i = 0; i < (*itr).second.size(); i++) {

			cout << "Name: " << categoryMap[(*itr).first][i]->name << endl;
			cout << "Age: " << categoryMap[(*itr).first][i]->age << endl;
		}
		itr++;
	}

	cout << "**********************************" << endl;

	do {

		cout << "Enter category to add (\"managers\",\"engineers\", or \"customers\"): ";
		getline(cin, category);

		if (category == "managers" || category == "Managers" || category == "customers" || category == "Customers" || category == "engineers" || category == "Engineers") {
			cout << "\nEnter Name: ";
			getline(cin, inputName);

			cout << "Enter Age: ";
			cin >> inputAge;
		}
		else {
			cout << "\nError 404! Category NOT found" << endl;
		}

		
		if (category == "managers" || category == "Managers") {
			managers.push_back(new Person(inputName, inputAge));
		}
		else if (category == "engineers" || category == "Engineers") {
			engineers.push_back(new Person(inputName, inputAge));
		}
		else if (category == "customers" || category == "Customers") {
			customers.push_back(new Person(inputName, inputAge));
		}
		
		cout << "Add again? (y or n): ";
		cin >> response;
		cin.ignore();
		cout << endl;

	} while (response == 'y' || response == 'Y');


	itr = categoryMap.begin();

	categoryMap["managers"] = managers;
	categoryMap["engineers"] = engineers;
	categoryMap["customers"] = customers;

	while (itr != categoryMap.end()) {
		cout << "Key: " << (*itr).first << ":-----------" << endl;
		for (int i = 0; i < (*itr).second.size(); i++) {

			cout << "Name: " << categoryMap[(*itr).first][i]->name << endl;
			cout << "Age: " << categoryMap[(*itr).first][i]->age << endl;
		}
		itr++;
	}

	//Memory Management
	while (!customers.empty() && !managers.empty() && !engineers.empty()) {
		customers.pop_back();
		managers.pop_back();
		engineers.pop_back();
	}

	system("pause");
	return 0;
}