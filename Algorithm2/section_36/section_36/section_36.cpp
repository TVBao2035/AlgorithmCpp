#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
Cho một mảng các số nguyên arr và một số nguyên dương k.
Hãy viết hàm trả về các phần tử âm đầu tiên trong cửa số k. 
Nếu không tồn tại số âm nào output 0. Xem ví dụ để hiểu rõ đề bài hơn.

Ví dụ:

Với arr = [-8 2 3 -6 10], k = 2 thì các cửa số lần lượt chứa các giá trị:
[-8, 2], [2, 3], [3, -6], [-6, 10]
nên kết quả trả về sẽ có dạng firstNegative(arr, k) = [-8, 0, -6, -6]
*/
vector<int> firstNegative(vector<int> arr, int index) {
	queue<int> negativeNumber;
	vector<int> result;
	int firstSite = 0;// vi tri bat dau 
	int legal = arr.size() - index; // lay tieu chuan 
	int store = 0;// kiem tra trong queue co so 0 khong neu khong push 0
	while (firstSite <= legal) {
		int i = firstSite;
		while (negativeNumber.size() < index) {//push phan tu tu vi tri firstSite co den kich thuoc queue == index
			negativeNumber.push(arr[i]);
			i++;//dich chuyen den phan tu ke tiep
		}
		while (!negativeNumber.empty()) {
			if (store == 0 && negativeNumber.front() < 0) {
				store = negativeNumber.front();// luu phan tu am vao bien sao do bo het cac phan tu con lai
				result.push_back(store);
			}
			negativeNumber.pop();
		}
		if (store == 0) result.push_back(0);
		firstSite++;
		store = 0;
	}
	return result;
}
int main()
{
	vector<int> arrayNumber;
	int index, lengthOfArray;
	cout << "enter length of array: "; cin >> lengthOfArray;
	for (int i = 0; i < lengthOfArray; i++) {
		int store; cin >> store; arrayNumber.push_back(store);
	}
	cout << endl << "enter index: "; cin >> index;
	arrayNumber = firstNegative(arrayNumber, index);
	for (int i : arrayNumber) cout << i << " ";
	return 0;
}