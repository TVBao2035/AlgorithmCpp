#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
Nhập vào một số nguyên dương n.

Hãy chuyển n thành mã nhị phân và in chuỗi đó ra màn hình.
*/
int main()
{
	stack <int> st;
	cout << "enter n: "; int n; cin >> n;
	while (n != 0) {
		st.push(n % 2);
		n /= 2;
	}
	string result = "";
	while (!st.empty()) {
		result += to_string(st.top());
		st.pop();
	}
	cout << "result: " << result;
	return 0;
}