#include<iostream>
using namespace std;
#include<stack>
#include<vector>
/*
Cho một biểu thức dưới dạng chuỗi và chỉ chứa hai loại ký tự là '{' và '}'. 
viết hàm output số biến đổi nhỏ nhất để biểu thức trở thành cân bằng hoặc output -1 nếu không thể đưa biểu thức về cân bằng.

Biểu thức cân bằng là biểu thức mà mỗi dấu '{' chỉ ứng với một dấu '}' và ngược lại.

Ví dụ "{{{}}{}}", "{}" là biểu thức cân bằng và "}{" là biểu thức không cân bằng, 
để chuyển biểu thức này về dạng cân bằng cần 2 phép biến đổi.
*/
int reversals(vector<char> descriptive) {
	stack<char> storeDescriptive;
	int size = descriptive.size();
	if (size % 2 != 0) return -1;
	for (int i = 0; i < size; i++) {
		if (descriptive[i] == '}') if (!storeDescriptive.empty() && storeDescriptive.top() == '{') {
			storeDescriptive.pop();
			continue;
		}
		storeDescriptive.push(descriptive[i]);
	}
	int count = 0;
	while (!storeDescriptive.empty()) {
		char firstKey = storeDescriptive.top();
		storeDescriptive.pop();
		char secondKey = storeDescriptive.top();
		storeDescriptive.pop();
		if (firstKey != secondKey) count++;
		count++;
	}
	return count;
}
int main()
{
	vector<char> descriptive;
	int size;
	cout << "enter number of descriptive:"; cin >> size;
	cout << "enter descriptive: " << endl;
	for (int i = 0; i < size; i++) {
		char store;
		do {
			cin >> store;
			if (store != '{' && store != '}') cout << "please enter again!";
		} while (store != '{' && store != '}');
		descriptive.push_back(store);
	}
	cout << "result: " << reversals(descriptive);
	return 0;
}