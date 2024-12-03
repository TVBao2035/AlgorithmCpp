#include<iostream>
#include<vector>
using namespace std;
/*
Cho một vector chứa các số nguyên, bạn hãy viết hàm trả về 
tổng của các phần tử lẻ trong vector đó.
*/
int sumOfOddElement(vector<int> vec) {
	int result = 0;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it % 2 != 0) result += *it;
	}
	return result;
}
int main()
{
	vector<int> vec;
	int n; cin >> n;
	cout << "enter to vector:" << endl;
	for (int i = 0; i < n; i++) {
		int store;
		cin >> store;
		vec.push_back(store);
	}
	cout << "result: " << sumOfOddElement(vec);
	
	return 0;
}