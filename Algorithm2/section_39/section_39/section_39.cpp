#include<iostream>
#include<map>
#include<string>

using namespace std;
/*
Cho một chuỗi s, hãy đưa ra một dãy lần lượt là các ký tự và số lần xuất hiện của nó, các ký tự sắp xếp theo thự tự từ điển.

Ví dụ:

Với s = "aacccd" thì countChar = ["a 2", "c 3", "d 1"].

Với s = "aabbbca" thì countChar = ["a 3", "b 3", "c 1"].
*/
int main()
{
	string code;
	bool checkSpace;
	do {
		cout << "Pleae! Enter Your Code: ";
		fflush(stdin);
		getline(cin, code);
		checkSpace = code.find(' ') != -1;
		if (checkSpace) {
			cout << "Code doesn't contain spaces. Please Enter Again!" << endl;
		}
	} while (checkSpace);
	map<char, int> mapCharInt;
	map<char, int>::iterator it;

	for (char x : code) mapCharInt[x]++;
	cout << "Result: " << endl;
	for (it = mapCharInt.begin(); it != mapCharInt.end(); it++) {
		string str = " ";
		str = it->first + str + to_string(it->second);
		cout << str << endl;
	}
	return 0;
}