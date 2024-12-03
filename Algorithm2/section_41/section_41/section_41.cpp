#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
/*
Cho 2 mảng các chuỗi arr1, arr2 dưới dạng vector. Ứng với mỗi chuỗi trong arr2 bạn cần tìm 
một chuỗi có thứ tự từ điển nhỏ nhất trong arr1 mà đứng sau arr2 trong từ điển. 
Nếu không có chuỗi nào trong arr1 thỏa mãn thì output "-1".

Ví dụ

Với arr1 = ["codelearn","learncode", "io"],
arr2 = ["code","war","io"]
Thì kết quả mong muốn greaterString(arr1, arr2) = ["codelearn","-1","learncode"]
*/

int main()
{
	map<string, bool> mapStringBool;
	vector<string> vectorFirst, vectorSecond;
	int lengthFirst, lengthSecond;
	cout << endl << "Enter Length Of First Vector and Length Of Second Vector: " << endl;
	cin >> lengthFirst >> lengthSecond;
	cout << "Enter Elements In First Vector " << endl;
	for (int i = 0; i < lengthFirst; i++) {
		string s; cin >> s;
		vectorFirst.push_back(s);
	}
	cout << "Enter Elements In Second Vector " << endl;
	for (int i = 0; i < lengthSecond; i++) {
		string s; cin >> s;
		vectorSecond.push_back(s);
	}

	for (auto x : vectorFirst) mapStringBool[x] = true;
	vector<string> result;
	for (auto x : vectorSecond) {
		if (mapStringBool.upper_bound(x) != mapStringBool.end()) {
			auto temp = mapStringBool.upper_bound(x);
			result.push_back(temp->first);
		}
		else result.push_back("-1");
	}
	for (auto x : result) cout << x << endl;
	return 0;
}