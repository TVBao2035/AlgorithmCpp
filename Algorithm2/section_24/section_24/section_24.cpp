#include<iostream>
#include<string>
#include<set>
using namespace std;
/*
Tính số lượng tiểu thiểu các ký tự cần thay đổi trong chuỗi str để chuỗi đó có k 
ký tự khác nhau hoặc xuất ra điều đó là không thể.

Chuỗi str chỉ bao gồm những chữ cái latinh viết thường và cũng chỉ có thể thay thành
những chữ cái latinh viết thường.

Ví dụ:

Với str = "yandex", k = 6 thì kết quả sẽ là diversity(s, k) = "0"

Với str = "google", k = 7 thì kết quả sẽ là diversity(s, k) = "impossible".

Với str = "codelearn", k = 9 thì kết quả sẽ là diversity(s, k) = "1"
So sánh str.length và k:

Nếu str.length() < k:
Trả về "impossible".
Nếu str.length() ≥ k:
Tạo một set s chèn từ  các ký từ trong str.
Nếu s.size() ≥ k:
Trả về 0.
Nếu s.size() < k:
Trả về k - s.size().*/

string diversity(string word, int key) {
	if (word.length() < key) return "impossible";
	else {
		set<char>storeChar(word.begin(), word.end());
		int sizeOfWord = storeChar.size();
		return (sizeOfWord < key) ? to_string(key - sizeOfWord) : "0";
	}
}
int main() {
	string word;
	int key;
	cout << "enter a word:"; fflush(stdin);
	getline(cin, word);
	cout << "enter a key: "; cin >> key;
	cout << "result: " << diversity(word, key);
	return 0;
}