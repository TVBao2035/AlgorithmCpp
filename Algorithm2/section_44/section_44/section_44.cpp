#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
TuanLQ7 Đơn giản 100 Điểm
Giới hạn ký tự: 3000
Bài tập.
Cho mỗi dãy số nguyên và một dãy số nguyên arr và một số nguyên dương sum.

Hãy kiểm tra xem dãy số có tồn tại hai số có tổng bằng sum hay không.

Ví dụ:

Với arr = [2,4,-1,9,8], sum = 6 thì checkSum(arr, sum) = true.

Với arr = [2,5,3,8,9], sum = 3 thì checkSum(arr, sum) = false.

Với arr = [4,7,3,5], sum = 6 thì checkSum(arr, sum) = false.
*/
int main()
{
	vector<int> array;
	int length;
	cout << "Enter Length Of Array: ";
	cin >> length;
	cout << endl << "Enter Elements In Array:" << endl;
	for (int i = 0; i < length; i++) {
		int temp; cin >> temp;
		array.push_back(temp);
	}
	int sum;
	cout << "Enter Sum: ";
	cin >> sum;
	map<int, bool> mapIntBool;
	bool checkSum = false;
	for (auto temp : array) {
		int otherSum = sum - temp;
		if (mapIntBool.find(otherSum) != mapIntBool.end()) {
			checkSum = true;
		}
		else {
			mapIntBool[temp] = true;
		}
	}
	string result = checkSum ? "true" : "false";
	cout << result;
	return 0;
}