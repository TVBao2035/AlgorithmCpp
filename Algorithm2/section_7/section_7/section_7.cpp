#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
Cho một sâu s chỉ gồm các ký tự viết thường, hãy viết hàm trả về chuỗi mã hóa của sâu này.
*/
int main()
{
	stack<char> st;
	cout << "enter one string:" << endl;
	string str; fflush(stdin); getline(cin, str);
	int count = 0;
	string result = "";
	int length = str.length();
	for (int i = 0; i < length+1; i++) {
		if (st.empty() || st.top() == str[i]) {
			st.push(str[i]);
		}else{
			result += st.top();
			while (!st.empty()) {
				count++;
				st.pop();
			}
			result += to_string(count);
			count = 0;
			st.push(str[i]);
		}
	}
	cout << "result: " << result << endl;
	return 0;
}