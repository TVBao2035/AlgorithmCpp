#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
Bạn được cho một chuỗi s đã được mã hóa, hãy viết hàm giải mã chuỗi này. Xem ví dụ để hiểu rõ hơn về cách giải mã.

Ví dụ

s = "3[a]", decodeString(s) = "aaa".
s = "3[ab]", decodeString(s) = "ababab".
s = "3[b2[ca]]", decodeString(s) = "bcacabcacabcaca".
s = "3[a3[b]1[ab]]", decodeString(s) = "abbbababbbababbbab".
*/
string decodeString(string code) {
	string result = "", store = "";
	int number =0 ;
	stack<char> decode;
	for (char word : code) {
		if (word != ']') {
			decode.push(word);
		}
		else {
			while (decode.top() != '[') {
				store = decode.top() + store;
				decode.pop();
			}
			decode.pop();
			int c = 1;
			while (!decode.empty() && decode.top() >= '0' && decode.top() <= '9') {
				number += (decode.top() - '0') * c;
				c *= 10;
				decode.pop();
			}
			for (int i = 0; i < number; i++) {
				for (char element : store) decode.push(element);
			}
			store = "";
			number = 0;
		}
	}
	while (!decode.empty()) {
		result += decode.top();
		decode.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string codeString;
	cout << "enter one code:";
	fflush(stdin); getline(cin, codeString);
	cout << endl << "result: " << decodeString(codeString);
	return 0;
}