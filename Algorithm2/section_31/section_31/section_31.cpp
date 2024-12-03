#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
/*
Cho một sâu s chỉ gồm các ký tự viết thường, hãy viết hàm trả về chuỗi mã hóa của sâu này.
Xem ví dụ để hiểu rõ hơn quá trình mã hóa

Ví dụ

Với s = "aaabbaaac" thì encodeString(s) = "a3b2a3c1".

Với s = "ab" thì encodeString(s) = "a1b1".

Với s = "aaddacc" thì encodeString(s) = "a2d2a1c2".
*/
string encodeString(string words) {
	string result = "";
	stack<char> storeWords;
	for (int i = 0;i<words.length()+1;i++) {
		if (!storeWords.empty() && words[i] != storeWords.top()) {
			result += storeWords.top();
			int count = 0;
			while (!storeWords.empty()) {
				count++;
				storeWords.pop();
			}
			result += to_string(count);
		}
		storeWords.push(words[i]);
	}
	return result;
}
int main()
{
	string words;
	cout << "enter code: "; cin >> words;

	string result = encodeString(words);
	cout << result;
	return 0;
}