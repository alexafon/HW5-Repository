///*************************************************************************
//** Author : Alexander Afonso
//** Program : hw5, q1
//** Date Created : April 14, 2024
//** Date Last Modified : April 14, 2024
//*************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include "listtools.h"
using namespace std;

struct Profile {
    string fullname;
    string state;
    bool operator==(Profile rhs) {
        if (fullname == rhs.fullname) return true; return false;
    }
    bool operator!=(Profile rhs) {
        if (fullname != rhs.fullname) return true; return false;
    }
};
ostream& operator<< (ostream &out, Profile &user) {
    out << user.fullname << "-" << user.state;
    return out;
}

bool searchDeque(deque<Profile> &pq, Profile &president) {
    for (auto it = pq.begin(); it != pq.end(); ++it) {
        if (it->fullname == president.fullname) {
            president = *it;
            return true;
        }
    }
    return false;
}

int main() {
	queue<Profile> pQueue;
	deque<Profile> pDeque;
    Profile temp;
    string line;
    string test = "truck	car";
    string token;
    stringstream ss(test);
    getline(ss, token, '\t');
    cout << token << endl;
    getline(ss, token, '\t');
    cout << token << endl;

    ifstream file("presidentsWstates.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
        }
    }
    cout << "Printing queue members by using pop and front***********************" << endl;
    cout << "Printing deque members with iterator***********************" << endl;
   
    file.clear();
    file.seekg(0);

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, temp.fullname, '\t');
        getline(ss, temp.state, '\t');
        pDeque.push_back(temp);
    }

    for (auto it = pDeque.begin(); it != pDeque.end(); ++it) {
        cout << *it << endl;
    }
	cout << "Printing deque members with indices***********************" << endl;
	//input any former president name to generate response
    temp.fullname = "Donald John Trump";
    if (searchDeque(pDeque, temp)) {
        cout << "president found:" << temp << endl;
    }
    else {
        cout << "president not found: " << temp << endl;
    }
    return 0;
}
