#include<iostream>
#include<vector>
using namespace std;
/*
	Cho một vector chứa các số nguyên, hãy tìm giá trị lớn nhất của tích của 2 
	số nguyên liên tiếp trong vector (đầu vào luôn đảm bảo vector có ít nhất 2 phần tử).
*/
int productOfTwoNumbers(vector<int>vec) {
	vector<int>::iterator it, its;
	int max = 0;
	for (it = vec.begin(); it != vec.end() - 1; it++) {
		its = it + 1;
		int store = *its * *it;
		if (store > max) max = store;
	}
	return max;
}
int main()
{
	vector<int> vec;
	int lengthOfVector;
	cout << "enter length of vector: "; cin >> lengthOfVector;
	cout << "enter elements of vector:" << endl;
	for (int i = 0; i < lengthOfVector; i++) {
		int store; cin >> store; vec.push_back(store);
	}
	cout << "result: " << productOfTwoNumbers(vec);
	return 0;
}