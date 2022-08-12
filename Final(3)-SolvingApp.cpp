

//Harry Patel

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> termSeperation(string arg);
double add(vector<int> cons);
vector<int> convert(vector<string> arg);

int main() {

    char response = 'y';
    string equation;
    do {

        cout << "Enter Equation: ";
        getline(cin, equation);

        equation.erase(remove_if(equation.begin(), equation.end(), isspace), equation.end());
        
        cout << "User: " << equation << endl;

        int equalIndex = equation.find('=');

        string LHS = equation.substr(0, equalIndex);
        string RHS = equation.substr(equalIndex + 1);
        if (RHS[0] != '-') {
            RHS = '+' + RHS;
        }

        vector<string> vectorLHS = termSeperation(LHS);
        vector<string>vectorRHS = termSeperation(RHS);
        vector<string>::iterator itrL = vectorLHS.begin();
        vector<string>::iterator itrR = vectorRHS.begin();

        vector<string>constantsToLHS;
        vector<string> variablesToRHS;

        //LHS
        while (itrL != vectorLHS.end()) {

            if ((*itrL).back() == 'x') {

                if ((*itrL).front() == '-') {
                    (*itrL).front() = '+';

                }
                else if ((*itrL).front() == '+') {
                    (*itrL).front() = '-';
                }
                variablesToRHS.push_back((*itrL));
            }
            else {
                constantsToLHS.push_back((*itrL));
            }
            itrL++;
        }

        //RHS
        while (itrR != vectorRHS.end()) {

            if ((*itrR).back() != 'x') {

                if ((*itrR).front() == '-') {
                    (*itrR).front() = '+';

                }
                else if ((*itrR).front() == '+') {
                    (*itrR).front() = '-';
                }
                constantsToLHS.push_back((*itrR));
            }
            else {
                variablesToRHS.push_back((*itrR));
            }
            itrR++;
        }
     
        vector<string> noX;
        vector<string> xs;
        itrR = variablesToRHS.begin();
        int flagR = 0;
        for (int i = 0; i < variablesToRHS.size(); i++) {

            if ((*itrR)=="x") {
                flagR = flagR + 1;
                xs.push_back((*itrR));
            }
            else if ((*itrR) == "-x") {
                flagR = flagR - 1;
                xs.push_back((*itrR));
            }
            else if ((*itrR).back() == 'x') {
                (*itrR).erase((*itrR).size() - 1);
                noX.push_back((*itrR));
            }
            itrR++;
        }

        vector<int> convertedLHS = convert(constantsToLHS);
        vector<int> convertedRHS = convert(noX);

        double addedLHS = add(convertedLHS);
        int addedRHS = add(convertedRHS) + flagR;
        double result = addedLHS / addedRHS;


        if (addedLHS == addedRHS) {
            cout << "App: Any real number is a solution." << endl;
        }
        else if (result <= INT_MAX) {
            cout << "App: x = " << result << endl;
        }
        else if (addedRHS == 0) {
            cout << "App: No Solution" << endl;
        }
        else {
            cout << "App: " << addedLHS << "/" << addedRHS << " (x = " << result << " )" << endl;
        }


        cout << "Enter Again? (y or n): ";
        cin >> response;
        cin.ignore();
        cout << endl;
    } while (response == 'y' || response == 'Y');

    system("pause");
    return 0;
}

vector<string> termSeperation(string arg) {
    int i = 0;
    string term;
    string op = "+";
    vector<string> terms;

    for (i = 0; i < arg.size(); i++) {

        if (arg.substr(i, 1) == "+" || arg.substr(i, 1) == "-") {
            if (term != "") {
                //cout << op + term << endl;
                terms.push_back(op + term);
            }
            op = arg.substr(i, 1);
            term = "";
        }
        else {
            term = term + arg.substr(i, 1);
        }
    }
    if (i == arg.size() && term != "") {
        //cout << op << term << endl;
        terms.push_back(op + term);
    }

    return terms;
}

double add(vector<int> cons) {
    double ans = 0;
    for (int i = 0; i < cons.size(); i++) {
        ans = ans + cons[i];
    }
    return ans;
}

vector<int> convert(vector<string> arg) {
    vector<int> ans;
    for (int i = 0; i < arg.size(); i++) {

        int c = stoi(arg[i]);
        ans.push_back(c);

    }
    return ans;
}