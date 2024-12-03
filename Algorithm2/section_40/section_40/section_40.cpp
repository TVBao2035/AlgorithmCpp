#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

/*
Bạn đã được cung cấp một chuỗi s làm đầu vào và bạn phải in biểu mẫu đã sửa đổi. Chuỗi được sửa đổi theo cách sau:

Những ký tự giống nhau chỉ lấy duy nhất một ký tự.
Ký tự nào có tần số xuất hiện trong chuỗi s nhiều hơn được sắp xếp trước.
Những ký tữ có cùng tần số xuất hiện thì sắp xếp theo thứ từ từ điển từ nhỏ đến lớn.
Ví dụ:

Với s = "codelearn" thì  modifyString = "eacdlnor".

Với s = "helloworld" thì  modifyString = "lodehrw".
*/
int main()
{
	map<char, int> mapCharInt;
	string words;

	bool checkSpace;
	do {
		cout << "Please Enter A Line Code: ";
		fflush(stdin);
		getline(cin,words);
		checkSpace = words.find(' ') != -1;
		if (checkSpace) {
			cout << "Code doesn't contain spaces. Please Enter Again!" << endl;
		}
	} while (checkSpace);

	for (char word : words) mapCharInt[word]++;

	vector<pair<char, int>> store(mapCharInt.begin(), mapCharInt.end());
	for (int i = 0; i < store.size()-1; i++) {
		for (int j = i + 1; j < store.size(); j++) {
			if (store[i].second < store[j].second) swap(store[i], store[j]);
			else if (store[i].second == store[j].second) {
				if (store[i].first > store[j].first) swap(store[i], store[j]);
			}
		}
	}
	for (int i = 0; i < store.size(); i++) cout << store[i].first << " " << store[i].second<<endl;
	return 0;
}