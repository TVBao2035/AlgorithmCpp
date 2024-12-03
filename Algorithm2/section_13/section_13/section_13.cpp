#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
Cho một vector chứa các xâu kí tự, bạn hãy viết hàm tìm những xâu có độ dài lớn nhất 
trong vector ban đầu và trả về kết quả tương ứng.
*/
vector<string>findLongestString(vector<string> vec) {
	vector<string> result;
	int sizeMax = vec[0].size();
	for (int i = 1; i < vec.size(); i++) {
		if (sizeMax < vec[i].size()) sizeMax = vec[i].size();
	}
	for (int i = 0; i < vec.size(); i++) {
		if (sizeMax == vec[i].size()) result.push_back(vec[i]);
	}
	return result;
}
int main()
{
	vector<string> vec;
	int sizeOfVector; cout << "enrer size of vector: "; cin >> sizeOfVector;
	cout << "enter strings in vector:" << endl;

	for (int i = 0; i < sizeOfVector; i++) {
		string store;
		fflush(stdin); getline(cin, store); vec.push_back(store);
	}
	cout << "result:" << endl;
	for (string x : findLongestString(vec)) cout << x << " ";
	return 0;
}