#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
Cho một string, nhiệm vụ của bạn là in chuỗi đảo ngược của string đó ra màn hình bằng cách dùng stack.
*/
int main()
{
	stack<char> st;
	string str;
	cout << "enter a string:" << endl;
	fflush(stdin);
	getline(cin, str);
	int length = str.length();
	for (int i = 0; i < length; i++) st.push(str[i]);
	string result = "";
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << "result:" << result << endl;
	return 0;
}