#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
/*
Cho một danh bạ điện thoại và danh sách các tên. Ứng với mỗi tên trong danh sách hãy đếm xem tên này là bắt đầu của bao nhiêu tên trong
danh bạ điện thoại, hay nói cách khác hãy đếm xem tên này là prefix của bao nhiêu tên trong danh bạ.

Ví dụ:

Với contacts = ["Codelearn", "Codewar"],
names = ["Code", "Codel", "io"]
thì countPrefix(contacts, names) = [2,1,0].
*/
void enterElements(vector<string> &array, int length) {
	for (int i = 0; i < length;i++){
		string temp;
		cin >> temp;
		array.push_back(temp);
	}
}

int main()
{
	vector<string> contacts , names;
	map<string, int> mapStringInt;
	int amountOfContacts, amountOfNames;
	cout << "enter amount of contacts and amount of names: " << endl;
	cin >> amountOfContacts >> amountOfNames;
	cout <<endl<< "enter elements in contacts" << endl;
	enterElements(contacts, amountOfContacts);
	cout <<endl<< "enter elements in names" << endl;
	enterElements(names, amountOfNames);
	
	cout << endl << endl << "result" << endl;
	for (int i = 0; i < amountOfNames; i++) {
		int count = 0;
		for (int j = 0; j < amountOfContacts;j++) {
			bool check = false;
			for (int k = 0; k < names[i].size();k++) {
				if (names[i][k]==contacts[j][k]) {
					check = true;
				}
				else {
					check = false;
					break;
				}
			}
			if(check) count++;
		}
		mapStringInt[names[i]] = count;
	}

	for (auto x : mapStringInt) cout << x.first << " " << x.second << endl;
	return 0;
}