#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*TuanLQ7 Đơn giản 100 Điểm
Giới hạn ký tự: 3000
Bài tập.
Cho hãy dãy số nguyên arr1 và arr2, hãy tính tổng những số xuất hiện trong cả hai dãy, 
lưu ý là mỗi số chỉ được tính một lần.

Ví dụ:

Với arr1 = [6, 7, 5, 4, 6, 8], arr2 = [2, 5, 7, 5, 3] thì  sumOfCommon(arr1, arr2) = 12.

Với arr1 = [5,6,7], arr2 = [2,3,4] thì sumOfCommon(arr1, arr2) = 0.*/
int main()
{
	vector<int> firstVector, secondVector;
	int firstLength, secondLength;
	cout << "Enter Length Of First Vector And Length Of Second Vector:" << endl;
	cin >> firstLength >> secondLength;
	cout << "Enter Elements In First Vector:" << endl;
	for (int i = 0; i < firstLength; i++) {
		int temp; cin >> temp;
		firstVector.push_back(temp);
	}
	cout << endl << "Enter ELements In First Vector:" << endl;
	for (int i = 0; i < secondLength; i++) {
		int temp; cin >> temp;
		secondVector.push_back(temp);
	}

	map<int, int> mapInt;
	
	for (auto x : firstVector) mapInt[x]++;
	int sum = 0;
	for (auto x : secondVector) {
		if (mapInt.find(x) != mapInt.end()) {
			auto temp = mapInt.find(x);
			if (temp->second != 0) {
				sum += temp->first;
				temp->second = 0;
			}
		}
	}
	cout << sum;
	return 0;
}